let str_replace = (target, ~regex, ~replace) => {
  let pattern = Str.regexp(regex);
  Str.global_replace(pattern, replace, target);
};

let re2_replace = (target, ~regex, ~replace) => {
  let pattern = Re2.create_exn(regex);
  Re2.replace_exn(~f=_ => replace, pattern, target);
};

let re_replace = (target, ~regex, ~replace) => {
  let pattern = Re.Pcre.regexp(regex);
  Re.replace_string(pattern, replace, target);
};

let () = {
  let str = "ABCdef";
  print_endline @@ re_replace(str, ~regex="ABC", ~replace="xxx");
};
