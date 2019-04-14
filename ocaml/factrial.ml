(* standard recursion *)
let rec fact1 n =
  if n <= 0 then
    1
  else
    fact1 (n - 1) * n
;;

(* tail call *)
(* n'は計算結果を持つ値 *)
let fact2 n =
  let rec iter i n' =
    if i <= 1 then
      n'
    else
      iter (i - 1) (n' * i)
  in
  iter n 1
;;

Printf.printf "%d\n" (fact1 10);
Printf.printf "%d\n" (fact2 10)