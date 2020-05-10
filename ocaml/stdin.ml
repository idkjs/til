open Printf

let rec read_lines ic =
  try
    let line = input_line ic in
    line :: read_lines ic
  with
  | End_of_file -> []
;;

let split_line line = Str.split (Str.regexp "[ \t]+") line

let () =
  let lines = read_lines stdin in
  List.iter (fun e -> printf "%s;;" e) lines
;;
