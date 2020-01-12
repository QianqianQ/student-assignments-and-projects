def if_sorted(lst):
    return all(a <= b for a, b in zip(lst[:-1], lst[1:]))


def if_reverse_sorted(lst):
    return all(a >= b for a, b in zip(lst[:-1], lst[1:]))


def if_unique(lst):
    if len(lst) > len(set(lst)):
        return False
    else:
        return True

def insertion_sort(lst):
    for i in range(len(lst)):
        temp = lst[i]
        j = i
        while(j > 0) and (temp < lst[j-1]):
            lst[j] = lst[j-1]
            j -= 1
        lst[j] = temp


def merge(lst1, lst2):
    lst = []
    while len(lst1) != 0 and len(lst2) != 0:
        if lst1[0] < lst2[0]:
            lst.append(lst1[0])
            lst1.remove(lst1[0])
        else:
            lst.append(lst2[0])
            lst2.remove(lst2[0])
    if len(lst1) == 0:
        lst += lst2
    else:
        lst += lst1
    return lst


def merge_sort(lst):
    if len(lst) <= 1:
        return lst
    if len(lst) <= 20:
        insertion_sort(lst)
    else:
        mid = int(len(lst)/2)
        left_lst = lst[:mid]
        right_lst = lst[mid:]
        a = merge_sort(left_lst)
        b = merge_sort(right_lst)
        lst = merge(a, b)
    return lst


def find_pivot(left,right):
    return int((left+right)/2)


def partition(lst, left, right, pivot):
    while left <= right:
        while lst[left] < pivot:
            left += 1
        while right >= left and lst[right] >= pivot:
            right -= 1
        if right > left:
            swap(lst, left, right)
    return left


def swap(lst,i,j):
    temp = lst[j]
    lst[j] = lst[i]
    lst[i]=temp


def quick_sort(lst,left,right):
    pivot = find_pivot(left,right)
    swap(lst,pivot,right)
    i = partition(lst,left, right-1,lst[right])
    swap(lst,i,right)
    if (i-left)>1:
        quick_sort(lst,left, i-1)
    if (right-i)>1:
        quick_sort(lst, i+1, right)


def my_sort(lst):
    """Return the sequence `lst` sorted in-place in ascending order."""
    # Note: in-place means, that the method shouldn't create and return
    # another list, but sort the same list object it received, and
    # return it.
    # It is allowed however, to copy values to another list and use it
    # to get the given list sorted. Note that this will take extra
    # memory though.
    # The solution must be fast in order to complete the biggest sorting
    # problems in time before the time runs out and the evaluator
    # terminates the attempt.
    # Note: If you are implementing a recursive mergesort, remember to
    # divide only up until a certain sublist size, eg. 20, and then sort
    # the sublist with another method, eg. selection sort. Dividing and
    # recursing up until sublists of size 1 is not effective!

    if len(lst) == 0 or len(lst) == 1:
        return lst
    elif if_sorted(lst):
        insertion_sort(lst)
        return lst
    elif (if_reverse_sorted(lst) and len(lst) < 100000) or (len(set(lst)) < 10):
        return merge_sort(lst)
    else:
        i = 0
        j = len(lst)
        quick_sort(lst, i, j-1)
        return lst

    # raise NotImplementedError('my_sort does not sort anything yet.')

