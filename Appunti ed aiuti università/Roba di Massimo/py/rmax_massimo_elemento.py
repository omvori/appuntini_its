def rmax( x ):
    try:
        for e in x:
            c = rmax(e)
            try:
                if c > m:
                    m = c
            except UnboundLocalError:
                m = c
        return m
    except TypeError:
        return x

a = [3, 9, [9, 0, [1, 2], 3], 7, [11, [2, 8], 9], 5 ]
print(rmax(a))