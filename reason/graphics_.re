open Graphics;

let () = {
  open_graph(" 640x480");
  for (i in 12 downto 1) {
    let radius = i * 20;
    print_endline("radius is " ++ string_of_int(radius));
    set_color(
      if (i mod 2 == 0) {
        green;
      } else {
        red;
      },
    );
    fill_circle(320, 240, radius);
    Unix.sleep(1);
  };
};
