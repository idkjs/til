open Core;

let fol = List.fold;
let l = ["1", "2", "3"];
let () =
  printf("%s\n") @@ List.fold(l, ~init="", ~f=(acc, x) => acc ++ " " ++ x);
