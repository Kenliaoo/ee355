file = open("in.txt","r")
string = file.read()
length = len(string)
first = 0
last = length -1 
error = 0
while(first<last):
    if(string[first]==string[last]):
        first=first+1
        last=last-1
    else:
        error += 1
        break
if(error == 0):
    print("Yes")
else:
    print("No")
