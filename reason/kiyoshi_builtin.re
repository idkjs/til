open Printf;

let count = (l, x) => List.filter(x' => x' == x, l) |> List.length;

let kiyoshi = () => {
  let is_kiyoshi = l =>
    if (List.hd(List.rev(l)) == "ドコ" && count(l, "ドコ") == 1) {
      true;
    } else {
      false;
    };

  Random.self_init();
  let s_l =
    List.init(5, _ => Random.bool())
    |> List.map(b => if (b) {"ズン"} else {"ドコ"});

  List.iter(s => printf("%s ", s), s_l);
  if (is_kiyoshi(s_l)) {
    printf("キヨシ!\n");
    true;
  } else {
    printf("\n");
    false;
  };
};

let () =
  while (!kiyoshi()) {
    ();
  };
