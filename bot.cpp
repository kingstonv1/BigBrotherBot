#include <dpp/dpp.h>
#include "info.h"

const std::string& firstMessageContents {"Go about your daily lives. There Is No Admin Abuse."};
//dpp::snowflake& generalChat = 965808852421455910;

int main() 
{
    dpp::cluster bot(BOT_TOKEN);
    bot.on_log(dpp::utility::cout_logger());

    if ( bot.on_message_create ) 
        {  }

    dpp::message newMessage(965808852421455910, firstMessageContents, dpp::mt_default);


    bot.on_ready( [&bot](const dpp::ready_t& event) 
    {
        if ( dpp::run_once<struct register_bot_commands>() ) 
        { 
            bot.set_presence(dpp::presence(dpp::ps_online, dpp::at_watching, " you.") ); 
            bot.global_command_create( dpp::slashcommand("ping", "Ping pong!", bot.me.id));
        }
    });


    bot.start(false);    
    return 0;

}