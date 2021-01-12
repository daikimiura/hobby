fun partition(_, nil) = (nil, nil)
|   partition(n, x::xs) =
  let
    val (a, b) = partition(n, xs)
  in
    if x < n then (x::a, b) else (a, x::b)
  end

fun quick_sort nil = nil
|   quick_sort (x::xs) =
  let
    val (m, n) = partition(x, xs)
  in
    quick_sort m @ (x :: quick_sort n)
  end