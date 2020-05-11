open Core;
open Sexplib;

/** type sexp = Atom of string | List of sexp list **/;

let () = {
  /* build s-expression: (This (is an) (s expression)) */
  let sexp1 =
    Sexp.(
      List([
        Atom("This"),
        List([Atom("is"), Atom("an")]),
        List([Atom("s"), Atom("expression")]),
      ])
    );

  /* Sexp object to string */
  print_endline(Sexp.to_string(sexp1));
  /* parse string and produce sexp object */
  let sexp2 = Sexp.of_string("(This (is an) (s expression))");
  assert(Sexp.compare(sexp1, sexp2) == 0);
  let sexp3 = Sexp.of_string("(1 . 3)");
  print_endline(Sexp.to_string(sexp3));
};
