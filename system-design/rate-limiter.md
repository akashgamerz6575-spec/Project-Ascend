# System Design: Distributed Rate Limiter

- **Target SLA:** $< 5\text{ms}$ response latency.
- **Scale:** $100\text{k}$ requests per second.

## Architecture
```mermaid
graph LR
    A[Client] --> B[API Gateway]
    B --> C[Rate Limiter Middleware]
    C --> D[(Redis Cache)]
```

## Decisions & Tradeoffs
- **Redis vs Memory:** Selected Redis to share rate limit tokens across distributed nodes, trading network latency for cluster parity.
