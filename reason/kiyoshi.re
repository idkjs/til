open Core;

let kiyoshi = () => {
  let is_kiyoshi = l =>
    if (List.last_exn(l) == "ドコ"
        && List.count(l, ~f=x => x == "ドコ") == 1) {
      true;
    } else {
      false;
    };

  Random.self_init();
  let s_l =
    List.init(5, ~f=_ => Random.bool())
    |> List.map(~f=b => if (b) {"ズン"} else {"ドコ"});

  List.iter(s_l, ~f=s => printf("%s ", s));
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
