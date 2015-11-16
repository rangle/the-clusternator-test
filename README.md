# clusternator-test-repo

This repository will be used to test the clusternator web hooks and CI configuration.

# SETUP

## Docker

#### Create a `Dockerfile`

TODO

#### Export dockerhub credentials

On CircleCI's enivronment configuration page, add the following environment
variables with the correct values:

- $DOCKER_EMAIL
- $DOCKER_USER
- $DOCKER_PASSWORD

You can see in our `circle.yml` we use those environment variables to
authenticate with dockerhub in order to push up our image.

```
docker login -e $DOCKER_EMAIL -u $DOCKER_USER -p $DOCKER_PASSWORD
```


## `circle.yml`

`circle.yml` is what you'll use to configure the CI server.
(TODO, link to docs)

#### Enable docker support

Paste the following at the top of your `circle.yml`

```
machine:
  services:
    - docker
```


#### Install clusternator

Add clusternator as a dependency.
(TODO maybe move to deploy step?)

```
dependencies:
  pre:
    - npm install -g clusternator
```


#### Build image and push to docker

```
test:
  post:
    - docker login -e $DOCKER_EMAIL -u $DOCKER_USER -p $DOCKER_PASSWORD
    - docker build -t rafkhan/hello-c .
    - docker push rafkhan/hello-c
```

## Setup Clusternator Hooks

This step involves adding hooks to *both our CI server* to generate builds,
*and on github* to close builds.

#### Github

TODO

#### CircleCI

TODO
