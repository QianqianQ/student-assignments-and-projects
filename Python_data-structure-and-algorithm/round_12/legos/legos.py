def suitable_pieces(width, pieces):
    pair1 = 0
    pair2 = 0
    abs = 0
    width = width*10000000
    
    if len(pieces)==0 or len(pieces)==1:
        result = ()
        return result

    if len(pieces)==2:
        if pieces[0]+pieces[1]==width:
            if pieces[0]<pieces[1]:
                result = (pieces[0],pieces[1])
            else:
                result = (pieces[1],pieces[0])
        else:
            result = ()
        return result
    
    pieces = list(filter(lambda x: x<width,pieces))
    pieces = sorted(pieces)
    
    '''
    for i in range(len(pieces)-1):
        for j in range(i+1,len(pieces)):
            if pieces[i]+pieces[j] == width and (pieces[j]-pieces[i])>=abs:
                    pair1=pieces[i]
                    pair2=pieces[j]
                    abs = pieces[j]-pieces[i]
    '''
    lo_index = 0
    hi_index = len(pieces) - 1
    while lo_index < hi_index:
        pair_sum = pieces[lo_index] + pieces[hi_index]
        if pair_sum < width:
            lo_index += 1
        elif pair_sum > width:
            hi_index -= 1
        else:
            if (pieces[hi_index]-pieces[lo_index])>=abs:
                pair1 = pieces[lo_index]
                pair2 = pieces[hi_index]
                abs = pieces[hi_index]-pieces[lo_index]
            lo_index +=1
            hi_index -=1
    
    
    if pair1==0:
        result = ()
    else:
        result = (pair1,pair2)
    
    return result

