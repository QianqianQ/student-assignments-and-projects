import numpy as np
def suitable_pieces(width, pieces):
    """
    Returns a tuple (L1, L2) where L1 and L2 are integers in `pieces` which have a sum equal to `width` such that abs(L1 - L2) is largest possible.
    If no pair in `pieces` have a sum equal to width, returns an empty tuple ().
    """
    pair1 = 0
    pair2 = 0
    abs = 0
    width = width*10000000
    
    if len(pieces)==0 or len(pieces)==1:
        result = ()
        return result

    for i in range(len(pieces)-1):
        for j in range(i+1,len(pieces)):
            if pieces[i]+pieces[j] == width and np.abs(pieces[i]-pieces[j])>=abs:
                    pair1=pieces[i]
                    pair2=pieces[j]
                    abs = np.abs(pieces[i]-pieces[j])
    

    if pair1==0:
        result = ()
        return result
    else:
        if pair1>pair2:
            temp = pair1
            pair1 = pair2
            pair2 = temp
        result = (pair1,pair2)
        return result


