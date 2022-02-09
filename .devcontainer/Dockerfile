# See here for image contents: https://github.com/microsoft/vscode-dev-containers/tree/v0.177.0/containers/cpp/.devcontainer/base.Dockerfile

# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT="ubuntu-20.04"
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# [Optional] Uncomment this section to install additional packages.
	# --no-install-recommends \
	# x11-utils \
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive && apt-get install -q -y \
	build-essential gdb clang lldb g++-10 \
	python3 \
	&& apt-get clean && rm -rf /var/lib/apt/lists/*
