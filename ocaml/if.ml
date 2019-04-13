let t = true;;
let f = false;;

let trueOrFalse b =
  if b then
    Printf.printf "True\n"
  else
    Printf.printf "False\n"

(* begin ... end (like Pascal) *)
let isTrue b =
  if b then
    begin
      Printf.printf "True\n";
      true
    end
  else
    begin
      Printf.printf "False\n";
      false
    end;;

let () =
  trueOrFalse t;
  trueOrFalse f;
  Printf.printf "returns %b\n" (isTrue t)
