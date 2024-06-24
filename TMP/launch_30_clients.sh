#!/bin/bash

for i in {1..30}
do
  ./zappy_ai -p 9008 -n luca -h 127.0.0.1 &
  sleep 0.3
done

wait