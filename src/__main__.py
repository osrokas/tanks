from display import Screen

window = Screen(
    game_name="Tanks",
    screen_size=(1200, 880),
    background_color="grey",
    game_box_width=1000,
    game_box_height=600,
)

window.create_game_window()
window.running_game()
