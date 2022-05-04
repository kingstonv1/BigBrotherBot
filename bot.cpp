#include <dpp/dpp.h>

const std::string BOT_TOKEN = "OTcxMzk1MTM4NTgyNjE0MDI2.G6xU_r.WG_lvW4jqGSxZ99qfH3Q40EOze1cdv8E9Op8rc";
const dpp::snowflake MY_GUILD_ID = 965808852421455903;
const std::string& firstMessage {"Go about your daily lives. There Is No Admin Abuse."};

int main() 
{
    dpp::cluster bot(BOT_TOKEN);

    bot.on_interaction_create([](const dpp::interaction_create_t& event) {
        if (event.command.get_command_name() == "ping") { event.reply ("Pong!"); }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) 
        {
            bot.global_command_create( dpp::slashcommand("ping", "Ping pong!", bot.me.id));
            bot.message_create(firstMessage);
        }

    });
    
    dpp::activity status = dpp::activity(3, " you.", "", "");
    bot.set_presence( dpp::activity.status );

    bot.start(false);
}