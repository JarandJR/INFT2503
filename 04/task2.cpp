#include <iostream>
#include <gtkmm.h>

class Window : public Gtk::Window {

private:
    Gtk::Entry entry1;
    Gtk::Entry entry2;
    Gtk::Button button;
    Gtk::Label label;
    Gtk::Box vbox;

public:
    Window() {
        set_title("Task 4");
        set_default_size(400, 400);
        set_position(Gtk::WIN_POS_CENTER);

        // Create the first text input field
        entry1.set_placeholder_text("Enter your first name");

        // Create the second text input field
        entry2.set_placeholder_text("Enter your last name");

        // Create a button
        button.set_label("Combine names");
        button.set_size_request(100, 50);
        button.signal_clicked().connect([this]() {
            on_button_clicked();
        });
        button.set_sensitive(false); // Disable the button by default

        // Create a vertical box to hold the text input fields
        vbox.set_orientation(Gtk::ORIENTATION_VERTICAL);
        vbox.set_margin_top(10);
        vbox.set_spacing(10); // Set spacing between widgets
        vbox.set_margin_start(10);
        vbox.set_margin_end(10);

        // Add the text input fields, button and label to the vertical box
        vbox.pack_start(entry1);
        vbox.pack_start(entry2);
        vbox.pack_start(button);
        vbox.pack_start(label);

        // Add the vertical box to the window
        add(vbox);

        entry1.signal_changed().connect([this]() {
            // Enable the button if both text input fields are not empty
            button.set_sensitive(!entry1.get_text().empty() && !entry2.get_text().empty());
        });

        entry2.signal_changed().connect([this]() {
            // Enable the button if both text input fields are not empty
            button.set_sensitive(!entry1.get_text().empty() && !entry2.get_text().empty());
        });

        show_all();
    }

protected:
    void on_button_clicked() {
        // Retrieve the text entered in the input fields
        std::string first_name = entry1.get_text();
        std::string last_name = entry2.get_text();

        // Combine the names
        std::string combined_name = first_name + " " + last_name;

        // Display the combined name in the label
        label.set_text("Names combined: " + combined_name);
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}