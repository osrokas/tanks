from display import Screen

window = Screen(
    game_name="Tanks",
    screen_size=(800, 600),
    background_color="grey",
    game_box_width=600,
    game_box_height=400,
)

window.create_game_window()
window.running_game()
