mapping = {
    '2':'abc','3':'def','4':'ghi','5':'jkl',
    '6':'mno','7':'pqrs','8':'tuv','9':'wxyz' 
}
def  backtrack(index,path,digits,res):
    if index == len(digits):
        res.append("".join(path))
        return
    for ch in mapping[digits[index]]:
        path.append(ch)
        backtrack(index+1,path,digits,res)
        path.pop()
        digits=input().strip()
        if digits:
            res=[]
            backtrack(0,[],digits,res)
            print("".join(res))
    