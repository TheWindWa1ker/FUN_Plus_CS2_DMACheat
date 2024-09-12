#pragma once

#include "Player.h"

extern Player players[64];
extern Map G_map;
extern int LocalPlayerControllerIndex;





namespace src
{
	class c_features
	{
	private:
		nlohmann::json m_data{};
		nlohmann::json m_player_data{};
		size_t m_bomb_idx{ 0 };

	public:
		nlohmann::json get_data() { return this->m_data; }

		void run()
		{


			const auto local_team = players[LocalPlayerControllerIndex].TeamID_Radar;


			this->m_data = nlohmann::json{};
			this->m_player_data = nlohmann::json{};

			this->m_data["m_local_team"] = local_team;

			this->get_map();
			this->get_player_info();
			//this->get_bomb_info();
		}

		void get_map()
		{

			this->m_data["m_map"] = G_map.map_name;
		}

		void get_player_info()
		{
			this->m_data["m_players"] = nlohmann::json::array();

				for(int i=0;i<64;i++)
				{
					if(players[i].Radar_Draw)
					{
						this->m_player_data["m_idx"] = i;
						this->m_player_data["m_name"] = players[i].PlayerName;
						if (i == LocalPlayerControllerIndex)
						{
							this->m_player_data["m_color"] = 1;
						}
						else
						{
							this->m_player_data["m_color"] = 0;
						}
						this->m_player_data["m_team"] = players[i].TeamID_Radar;
						this->m_player_data["m_health"] = players[i].Health;
						this->m_player_data["m_armor"] = players[i].armor;
						this->m_player_data["m_position"]["x"] = players[i].Pos_Radar.x;
						this->m_player_data["m_position"]["y"] = players[i].Pos_Radar.y;
						this->m_player_data["m_eye_angle"] = players[i].ViewAngle_Radar.y;
						this->m_player_data["m_is_dead"] = !players[i].IsAlive_Radar;
						this->m_player_data["m_model_name"] = players[i].model_path.substr(players[i].model_path.rfind("/") + 1, players[i].model_path.rfind(".") - players[i].model_path.rfind("/") - 1);
						this->m_player_data["m_steam_id"] = 123;
						this->m_player_data["m_money"] = players[i].money_Radar;
						this->m_player_data["m_has_helmet"] = players[i].helmet_Radar;
						this->m_player_data["m_has_defuser"] = players[i].defuser_Radar;
						this->m_player_data["m_weapons"] = nlohmann::json{};
						this->m_player_data["m_has_bomb"] = 0;

						this->m_player_data["m_weapons"]["m_active"] = players[i].weapon_name_Radar;
	

						set<string> utilities_set{};
						set<string> melee_set{};

						for (int k = 0; k < players[i].Weapon_num_Radar; k++)
						{
							switch ((e_weapon_type)players[i].AllWeapon[k].weapon_id_Radar)
							{
							case e_weapon_type::submachine_gun:
							case e_weapon_type::rifle:
							case e_weapon_type::shotgun:
							case e_weapon_type::sniper_rifle:
							case e_weapon_type::machine_gun:
								this->m_player_data["m_weapons"]["m_primary"] = players[i].AllWeapon[k].weapon_name_Radar;
								break;

							case e_weapon_type::pistol:
								this->m_player_data["m_weapons"]["m_secondary"] = players[i].AllWeapon[k].weapon_name_Radar;
								break;

							case e_weapon_type::knife:
								melee_set.insert(players[i].AllWeapon[k].weapon_name_Radar);
								break;

							case e_weapon_type::grenade:
								utilities_set.insert(players[i].AllWeapon[k].weapon_name_Radar);
								break;
							}
						}
						this->m_player_data["m_weapons"]["m_melee"] = vector<string>(melee_set.begin(), melee_set.end());
						this->m_player_data["m_weapons"]["m_utilities"] = vector<string>(utilities_set.begin(), utilities_set.end());

						this->m_data["m_players"].push_back(this->m_player_data);
					}
				}




			
		}

	};
}
inline src::c_features m_features{};