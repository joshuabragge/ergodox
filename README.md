<!-- -*- mode: markdown; fill-column: 8192 -*- -->

joshua's layout
======================

This is a colemak layout for the [ErgoDox Ez][ergodox-ez]. This is designed for SimCorp Business System Anaylst in Windows.

[ergodox-ez]: https://ergodox-ez.com/

## Table of Contents

* [Layouts](#layouts)
    - [Base layer](#base-layer)
    - [Movement layer](#movement-layer)
    - [Symbols layer](#symbols-layer)
    - [LED states](#led-states)
* [Building](#building)
* [Changelog](https://github.com/algernon/ergodox-layout/blob/master/NEWS.md#readme)

# Layouts

## Base layer

[![Base layer](https://github.com/joshuabragge/ergodox/blob/master/images/base-layer.png)](http://www.keyboard-layout-editor.com/#/gists/28f7eb305fdbff943613e1dc7aa9e82b)

This is a Colemak layout, influenced heavily by the greatst keyboard layout thinker of our time, [algernon][algernon] and his [blog][blog]

[algernon]: https://github.com/algernon/ergodox-layout
[blog]: https://asylum.madhouse-project.org/blog/tags/ergodox/

Features:
* Tapping the `ESC` key once yields `ESC`. Double-tapping the `ESC` key triggers `ALT`+`F4`,
* Dedicated Windows lock button.
* Dedicated `CTRL`+`ALT`+`DEL` button.
* When holding the `Tab`/**Arrow** key, the arrow layer activates while the key is held. Tapping the key produces the normal, `Tab` key. Double-tapping it toggles the **Arrow** layer on until a third tap. Credit [algernon][algernon].
* Tapping the `:` key once yields `:`, tapping it twice yields `;`. Credit [algernon][algernon].
* Tapping the `[{(`/`)}]` keys once yields `[` (or `{` when shifted), tapping them twice yields `(`. Credit [algernon][algernon].

## Movement layer

[![Movement layer](https://github.com/joshuabragge/ergodox/blob/master/images/movement-layer.png)](http://www.keyboard-layout-editor.com/#/gists/45681a17453d235925b6028dd83bf12a)

Features:
* VIM like arrow keys over home row.
* VIM like mouse keys over home row.
* Copy, paste, cut and undo buttons.
* Mousewheel buttons

## Symbols layer

[![Symbols layer](https://github.com/joshuabragge/ergodox/blob/master/images/symbols-pad.png)](http://www.keyboard-layout-editor.com/#/gists/401ef9a84369e47c57f9aedcf0a0d667)

This places the symbols under the home row fingers and minimizes the need to hold `SHIFT`+NUM. This idea holds true for the number pad.

## LED states

For the layers, the following colours apply:

* When the **Base** layer is active, no LEDS are on.
* When the **Symbols** layer is active, the *red* will turn on.
* When the **Movement** layer is active, the *green* will turn on

# Building

```
$ git clone https://github.com/qmk/qmk_firmware.git
$ cd qmk_firmware
$ git clone https://github.com/joshuabragge/ergodox \
            layouts/community/ergodox/ergodox-jb
$ make ergodox_ez:ergodox-jb
