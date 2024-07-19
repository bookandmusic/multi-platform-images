# Stage 1: Build the executable using a Go builder image
# Use the image of the current building machine with the same architecture
FROM --platform=$BUILDPLATFORM golang:1.21.9-alpine AS builder

# Set the working directory inside the container
WORKDIR /app

# Copy the Go source code to the working directory
COPY . .

# Cross-compile the Go program for Linux
# GOOS=linux specifies the target OS as Linux
# GOARCH=$TARGETARCH specifies the target architecture (e.g., amd64, arm64)
RUN GOOS=linux GOARCH=$TARGETARCH go build -o system_info

# Stage 2: Create a smaller image to run the executable
# Do not specify the image architecture, default is the target platform architecture
FROM alpine:latest

# Set the working directory inside the container
WORKDIR /app

# Copy the compiled executable from the builder stage
COPY --from=builder /app/system_info .

# Set the entry point to run the executable
ENTRYPOINT ["./system_info"]
