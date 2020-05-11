open Core;

/* 1h */
let h = 3600;

/* 1m */
let m = 60;

let () = {
  let s = h * 3 + m * 2 + 3;
  let to_string = seconds => {
    let hours = seconds / 3600 mod 100;
    let minutes = seconds mod 3600 / 60;
    let sec = seconds mod 60;
    printf("%02d:%02d:%02d", hours, minutes, sec);
  };

  to_string(s);
};
