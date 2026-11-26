FROM debian:trixie-slim AS build
RUN apt-get update && apt-get install -y --no-install-recommends g++ cmake make
WORKDIR /src
COPY . .
RUN cmake -S . -B build && cmake --build build --parallel

FROM build AS test
RUN ctest --test-dir build --output-on-failure

FROM debian:trixie-slim AS runtime
RUN useradd --create-home appuser
COPY --from=build /src/build/main /usr/local/bin/shapeclass
USER appuser
CMD ["shapeclass"]
