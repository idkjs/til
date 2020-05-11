open Core;

let () = {
  let str = "String ABCdef";
  let replace =
    Staged.unstage(String.tr_multi(~target=str, ~replacement="aaaa"));
  printf("%S\n", replace(str));
};
