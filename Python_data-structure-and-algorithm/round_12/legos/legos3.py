import itertools
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
    
    if not pieces:
        return ()

    comb = list(itertools.combinations(pieces,2))
    comb_list =[list(t) for t in comb]
    for i in comb_list:
        if i[0]+i[1]==width and np.abs(i[0]-i[1])>=abs:
            abs = np.abs(i[0]-i[1])
            pair1 = i[0]
            pair2 = i[1]

    if pair1==0:
        result = ()
        return ()
    else:
        if pair1>pair2:
            temp = pair1
            pair1 = pair2
            pair2 = temp
        result = (pair1,pair2)
        return result


