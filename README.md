# cs106L-assignment1
Assignment #1 for CS106L. Check out our course website [here](http://cs106l.stanford.edu)!


## resources

[课程链接](https://web.stanford.edu/class/archive/cs/cs106l/cs106l.1212/assignments.html)

## commands

dockerfile from the parent directory

```bash
docker build -t cs106l .
```

```bash
docker run -it --name cs106l -v $(pwd)/cs106L-assignment1:/assignment1 \
-v $(pwd)/cs106L-assignment2:/assignment2 \
-p 30022:22 cs106l
```
