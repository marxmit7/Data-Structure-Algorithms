if __name__ == '__main__':
    n = int(raw_input())
    list=[]
    for _ in range(n):
        fullcmd=raw_input().split()
        cmd=fullcmd[0]
        args=fullcmd[1:]
        if cmd!="print":
            cmd+="("+",".join(args)+")"
            eval("list."+cmd)
        else:
            print list
