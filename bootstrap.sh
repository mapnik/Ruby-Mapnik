#!/bin/bash

set -e

# Things included by travis
apt-get update -y
apt-get -y install software-properties-common ruby1.9.1 ruby1.9.1-dev

# Travis from this point onwards
apt-add-repository --yes ppa:mapnik/nightly-2.3
apt-add-repository --yes ppa:mapnik/nightly-trunk
apt-get update -y

apt-get -y install g++ gcc
apt-get -y install gcc-4.8 g++-4.8
gem install rake-compiler rake hoe rice chunky_png cairo

apt-get -y install libmapnik=2.3.0* mapnik-utils=2.3.0* libmapnik-dev=2.3.0* mapnik-input-plugin*=2.3.0*
make clean
make test
