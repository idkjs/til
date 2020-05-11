open Printf;

let print_list = l => {
  let len = List.length(l);
  print_string("[");
  List.iteri(
    (i, e) => {
      printf("%d;", e);
      if (i == len - 1) {
        printf("]");
      } else {
        printf(" ");
      };
    },
    l,
  );
};

let l = [5, 4, 3, 2, 1];

let () = {
  printf("%d\n") @@ List.hd(l);
  List.iter(printf("%d ")) @@ List.tl(l);
  print_endline("");
  /* iter with index */
  let pretty_print = (i, e) => printf("index: %d, element: %d\n", i, e);
  List.iteri(pretty_print, l);
  /* map */
  let triple = List.map(n => n * 3, l);
  print_list(triple);
  print_endline("");
  /* Handred times other than 2nd element (map with index) */
  let hundred =
    List.mapi(
      (i, n) =>
        switch (i) {
        | 1 => n
        | _ => n * 100
        },
      l,
    );

  print_list(hundred);
};
