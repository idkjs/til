open Core;

let uniq = l =>
  List.rev(
    {
      let rec iter = (x, l) =>
        switch (l) {
        | [] => x
        | [hd, ...tl] => iter([hd, ...x], List.filter(tl, ~f=x => x != hd))
        };

      iter([], l);
    },
  );

let () = List.iter(uniq([1, 1, 2, 3, 4, 5, 5]), ~f=x => printf("%d\n", x));
