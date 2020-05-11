let rec tarai = ((x, y, z)) =>
  if (x <= y) {
    y;
  } else {
    tarai((
      tarai((x - 1, y, z)),
      tarai((y - 1, z, x)),
      tarai((z - 1, x, y)),
    ));
  };

let () = Printf.printf("%d\n") @@ tarai((14, 7, 0));
