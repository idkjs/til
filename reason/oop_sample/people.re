open Core;
/* include local module */
open Person;

let () = {
  let john = new person;
  print_endline @@ john#get_fullname;
};
