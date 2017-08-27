def swap_case(s):
    ch=""
    for i in range(len(s)):

        if s[i].islower():
            ch+=s[i].upper()
        elif s[i].isupper():
            ch+=s[i].lower()
        else :
            ch+=s[i]
        i=i+1

    print ch

s=raw_input()
swap_case(s)
