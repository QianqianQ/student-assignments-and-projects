import numpy as np
def suitable_pieces(width, pieces):
    """
    Returns a tuple (L1, L2) where L1 and L2 are integers in `pieces` which have a sum equal to `width` such that abs(L1 - L2) is largest possible.
    If no pair in `pieces` have a sum equal to width, returns an empty tuple ().
    """
    pairs = []
    abs = []
    width = width*10000000
    
    for i in range(len(pieces)-1):
        for j in range(i+1,len(pieces)):
            if pieces[i]+pieces[j] == width:
                temp=[]
                temp.append(pieces[i])
                temp.append(pieces[j])
                pairs.append(temp)
                abs.append(np.abs(pieces[i]-pieces[j]))
    
    if not pairs:
        return ()
    else:
        max_index = abs.index(max(abs))
        result = pairs[max_index]
        if result[0]>result[1]:
            temp = result[0]
            result[0]=result[1]
            result[1]=temp
        result = tuple(result)
        return result


