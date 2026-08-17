# ── Satoxcoin Core 4.0 Dockerfile ─────────────────────────────────────────────
# Multi-stage build: build from source → minimal runtime image
# Usage: docker build -t satoxcoind .
#        docker run -v satoxcoin_data:/var/lib/satoxcoin satoxcoind
# ──────────────────────────────────────────────────────────────────────────────

# ── Build stage ──────────────────────────────────────────────────────────────
FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y --no-install-recommends \
    cmake g++ python3 \
    libboost-dev libevent-dev libsqlite3-dev \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /src
COPY . .

RUN cmake -B build \
    -DCMAKE_BUILD_TYPE=Release \
    -DENABLE_IPC=OFF \
    -DENABLE_WALLET=ON \
 && cmake --build build -j$(nproc) \
 && cmake --build build --target satoxcoind \
 && cmake --build build --target satoxcoin-cli

# ── Runtime stage ────────────────────────────────────────────────────────────
FROM ubuntu:24.04

RUN apt-get update && apt-get install -y --no-install-recommends \
    libboost-system1.83.0 libboost-filesystem1.83.0 libboost-thread1.83.0 \
    libevent-2.1-7 libsqlite3-0 \
 && rm -rf /var/lib/apt/lists/*

# Create service user
RUN useradd -r -s /bin/false satoxcoin \
 && mkdir -p /var/lib/satoxcoin \
 && chown satoxcoin:satoxcoin /var/lib/satoxcoin

COPY --from=builder /src/build/bin/satoxcoind /usr/local/bin/
COPY --from=builder /src/build/bin/satoxcoin-cli /usr/local/bin/

VOLUME ["/var/lib/satoxcoin"]
EXPOSE 60777/tcp
EXPOSE 18333/tcp

USER satoxcoin

ENTRYPOINT ["satoxcoind"]
CMD ["-datadir=/var/lib/satoxcoin", "-printtoconsole", "-onlynet=ipv4"]
