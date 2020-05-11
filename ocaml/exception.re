open Core;

/* 例外定義 */
exception User_error;

let () = {
  let _ =
    try(raise(User_error)) {
    | User_error => printf("catch exception \"Exit\"\n")
    | _ => printf("catch other exception")
    };

  /* evaluate */
  printf("end of extern\n");
  try(raise(Exit)) {
  | Exit => printf("catch exception \"Exit\"\n")
  | _ =>
    printf("catch other exception");
    /* not evaluate (still in `with` statement) */
    printf("in `with` statement");
  };
  printf("evaluate");
  /* finally */
  try(
    Core.protect(
      /* fの中でexceptionが発生してもfinallyの中身は必ず実行される */
      ~f=() => raise(Failure("fail")),
      ~finally=() => print_endline("finally"),
    )
  ) {
  | _ => printf("Exception")
  };
};
