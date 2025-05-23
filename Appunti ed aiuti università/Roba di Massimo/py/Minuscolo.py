def minuscolo( x ):
    '''
    Parameters
    ----------
    x : lettera maiuscola

    Returns
    -------
    la miuscola di x
    '''
    return chr(ord(x) + ord('a') - ord('A'))
b='B'
print(minuscolo(b))

