open Core;

let l = [1, 2, 3, 4, 5];

let () = {
  let str_l = List.fold(l, ~init="", ~f=(acc, x) => acc ++ string_of_int(x));
  printf("%s\n", str_l);
};
