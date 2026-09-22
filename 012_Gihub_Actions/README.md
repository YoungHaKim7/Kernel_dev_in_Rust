# Github Action(260923기준글)
### Software difference between Ubuntu 24.04 and Ubuntu 26.04

| Tool name | Ubuntu 24.04 | Ubuntu 26.04 | Notes |
|-----------|--------------|--------------|-------|
| Operating system | Ubuntu 24.04.5 LTS | Ubuntu 26.04.1 LTS | New Ubuntu LTS release |
| Kernel | 6.17.0-1022-azure | 7.0.0-1012-azure | Updated with the new operating system |
| Systemd | 255.4-1ubuntu8.17 | 259.5-0ubuntu3.4 | Updated with the new operating system |
| Docker Buildx | 0.37.0 | 0.37.0 | Available on both images |
| Minikube | 1.39.0 | 1.39.0 | Available on both images |
| AWS CLI | 2.36.40 | 2.36.40 | Available on both images |
| Azure CLI | 2.90.0 | 2.90.0 | Available on both images |
| Google Cloud CLI | 583.0.0 | 583.0.0 | Available on both images |
| Rust | 1.98.1 | 1.98.1 | Available on both images |
| Firefox | 155.0 | 155.0 | Available on both images |
| Java | 17.0.20+1 (default) | 17.0.20+1 (default) | Default version remains Java 17 |

- https://github.com/actions/runner-images/issues/14748
