
multirun
========

A simple Unix utility in C to run multiple commands concurrently.

* A very light alternative to classic init processes or supervisord to run multiple services in the same Docker container.
* Is dead-simple to use.
* Can be run without root permissions.
* Cleanly kills all the processes it starts.
* Delegates the restart duty to the upper level.
* Forwards stdout and stderr for proper logging with Docker.

Usage: `multirun "command1" "command2" ...`

You can also add the `-v` option to get a full log of the processes it starts and kills.

multirun never attempts to restart one of its children if it crashes. Instead it will kill all its other children before exiting with an error code. This behavior is ideal for a Docker container as the restart behavior can be delegated to the upper level, as example using systemd or Docker restart policies.

Installation
------------

### Binary using glibc (Ubuntu, Debian, Red Hat, Centos...)

    wget https://github.com/nicolas-van/multirun/releases/download/0.3.0/multirun-ubuntu-0.3.0.tar.gz && \
    tar -zxvf multirun-ubuntu-0.3.0.tar.gz && \
    mv multirun /bin && \
    rm multirun-ubuntu-0.3.0.tar.gz
    
### Binary using musl libc (Alpine)

    wget https://github.com/nicolas-van/multirun/releases/download/0.3.0/multirun-alpine-0.3.0.tar.gz && \
    tar -zxvf multirun-alpine-0.3.0.tar.gz && \
    mv multirun /bin && \
    rm multirun-alpine-0.3.0.tar.gz
    
### Sources

    git clone --branch 0.3.0 https://github.com/nicolas-van/multirun.git && \
    cd multirun && \
    make && \
    cp multirun /bin && \
    cd .. && \
    rm -rf multirun

## Contributing

[See the contribution guide.](CONTRIBUTING.md)

## License

[See the license](LICENSE.md)
