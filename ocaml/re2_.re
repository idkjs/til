open Core;
open Re2;

let pattern1 = Re2.create_exn("[A-Z]*");
let pattern2 = Re2.create_exn("[A-Z]");
let pattern3 = Re2.create_exn("[a-z]*");
let pattern4 = Re2.create_exn("Z");

let unwrap =
  fun
  | Ok(x) => x
  | Error(_) => [];

let () = {
  let matches = Re2.find_all_exn(pattern1, "ABCdef");
  List.iter(matches, ~f=s => printf("%S\n", s));
  let matches = Re2.find_all_exn(pattern2, "ABCdef");
  List.iter(matches, ~f=s => printf("%S\n", s));
  let matches = Re2.find_all_exn(pattern3, "ABCdef");
  List.iter(matches, ~f=s => printf("%S\n", s));
  let matches = Re2.find_all(pattern4, "ABCdef");
  List.iter(unwrap(matches), ~f=s => printf("%S\n", s));
};
