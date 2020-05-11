open Core;

/* compile with `-pkg ppx_deliving.show` option */

[@deriving show]
type two_ints = (int, int);
[@deriving show]
type obj = {key: string};

let () = {
  let two_ints_ = (3, 12);
  print_endline @@ show_two_ints(two_ints_);
  print_endline @@ show_obj({key: "hogehoge"});
};
