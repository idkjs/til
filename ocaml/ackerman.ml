let rec ack n m =
  if m = 0 then n + 1 else if n = 0 then ack (m - 1) 1 else ack (m - 1) (ack m (n - 1))
;;

let () = print_int @@ ack 2 2
