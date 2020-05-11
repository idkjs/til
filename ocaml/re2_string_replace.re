open Core;
open Re2;

let str = "string";

let replace = (target, regex, to_) => {
  let pattern = Re2.create_exn(regex);
  Re2.replace_exn(~f=_ => to_, pattern, target);
};

let () = {
  print_endline @@ replace(str, "ing", "aaa");
  print_endline @@ replace(str, "aaa", "bbb");
};
