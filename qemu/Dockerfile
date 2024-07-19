# Stage 1: Build the executable
FROM gcc:bookworm AS builder

# Set the working directory inside the container
WORKDIR /app

# Copy the C source code to the working directory
COPY . .

# Compile the C program
RUN gcc -o system_info system_info.c

# Stage 2: Create a smaller image to run the executable
FROM debian:bookworm-slim

# Set the working directory inside the container
WORKDIR /app

# Copy the compiled executable from the builder stage
COPY --from=builder /app/system_info .

# Set the entry point to run the executable
ENTRYPOINT ["./system_info"]
