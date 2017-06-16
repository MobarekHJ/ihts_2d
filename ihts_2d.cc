#include <deal.II/base/quadrature_lib.h>
#include <deal.II/base/function.h>
#include <deal.II/base/logstream.h>
#include <deal.II/base/tensor_function.h>
#include <deal.II/base/conditional_ostream.h>
#include <deal.II/base/mpi.h>
#include <deal.II/base/utilities.h>
#include <deal.II/base/timer.h>
#include <deal.II/base/parameter_handler.h>

#include <deal.II/lac/vector.h>
#include <deal.II/lac/full_matrix.h>
#include <deal.II/lac/dynamic_sparsity_pattern.h>
#include <deal.II/lac/sparse_matrix.h>
#include <deal.II/lac/sparsity_tools.h>
#include <deal.II/lac/solver_bicgstab.h> 
#include <deal.II/lac/solver_cg.h>
#include <deal.II/lac/solver_gmres.h>
#include <deal.II/lac/precondition.h>

#include <deal.II/distributed/shared_tria.h>

#include <deal.II/lac/petsc_parallel_vector.h>
#include <deal.II/lac/petsc_parallel_sparse_matrix.h>
#include <deal.II/lac/petsc_solver.h>
#include <deal.II/lac/petsc_precondition.h>

#include <deal.II/grid/tria.h>
#include <deal.II/grid/grid_generator.h>
#include <deal.II/grid/grid_refinement.h>
#include <deal.II/grid/tria_accessor.h>
#include <deal.II/grid/tria_iterator.h>
#include <deal.II/grid/grid_tools.h>
#include <deal.II/grid/grid_in.h>
#include <deal.II/grid/grid_out.h>

#include <deal.II/dofs/dof_handler.h> 
#include <deal.II/dofs/dof_accessor.h>
#include <deal.II/dofs/dof_accessor.templates.h>
#include <deal.II/dofs/dof_tools.h>
#include <deal.II/dofs/dof_renumbering.h>

#include <deal.II/fe/fe_values.h>
#include <deal.II/fe/fe_q.h>

#include <deal.II/numerics/vector_tools.h>
#include <deal.II/numerics/matrix_tools.h>
#include <deal.II/numerics/data_out.h>
#include <deal.II/numerics/error_estimator.h>
#include <deal.II/numerics/solution_transfer.h>

#include <fstream>
#include <iostream>
#include <sstream> 
#include <math.h>
#include <map>
#include <sys/stat.h>

#include <Material.h>
#include "Names.h"
#include "SurfaceCoefficients.h"
#include "AnalyticSolution.h"
#include "BoundaryConditions.h"
#include "DataTools.h"
//#include "MaterialData.h"

#include "parameters_ihts_2d.h"

namespace TRL
{
  using namespace dealii;
#include "PipeConvectiveCoefficient.h"
#include "PipeSystem.h"
  
  template<int dim>
  class BoundaryFlux:public Function<dim>
  {
  public:
    BoundaryFlux(std::vector<double> met_data);
    
    virtual double value (const Point<dim> &p,
			  const unsigned int component=0) const;
    virtual void value_list (const std::vector<Point<dim> > &points,
			     std::vector<double> &values,
			     const unsigned int component=0) const;
  private:
    /*
     * Default constructor for the inner class?
     */
    // BoundaryConditions boundary_condition(false/*analytic*/,
    // 					  0./* time_step*timestep_number*/,
    // 					  0./*air_temperature*/,
    // 					  0./*solar_radiation*/,
    // 					  0./*wind_speed*/,
    // 					  0./*relative_humidity*/,
    // 					  0./*precipitation*/,
    // 					  0./*surface_temperature*/,
    // 					  0./*,new_surface_pressure*/,
    // 					  false/*moisture_movement*/);
  };
  
  template <int dim>
  BoundaryFlux<dim>::BoundaryFlux(std::vector<double> met_data):Function<dim>()
  {
    // boundary_condition(false/*analytic*/,
    // 		       met_data[0]/* time_step*timestep_number*/,
    // 		       met_data[1]/*air_temperature*/,
    // 		       met_data[2]/*solar_radiation*/,
    // 		       met_data[3]/*wind_speed*/,
    // 		       met_data[4]/*relative_humidity*/,
    // 		       met_data[5]/*precipitation*/,
    // 		       met_data[6]/*surface_temperature*/,
    // 		       met_data[7]/*,new_surface_pressure*/,
    // 		       false/*moisture_movement*/);
  }
  
  template <int dim>
  double BoundaryFlux<dim>::value(const Point<dim> &p,
				   const unsigned int) const
  {
    // BoundaryConditions boundary_condition(false/*analytic*/,
    // 					  0./* time_step*timestep_number*/,
    // 					  air_temperature,
    // 					  solar_radiation,
    // 					  wind_speed,
    // 					  relative_humidity,
    // 					  precipitation,
    // 					  surface_temperature,
    // 					  0./*,new_surface_pressure*/,
    // 					  false/*moisture_movement*/);
    // double canopy_temperature=0.;
    // if (local_author=="Best")
    //   {
    // 	canopy_temperature
    // 	  =boundary_condition
    // 	  .get_canopy_temperature(local_author,
    // 				  canopy_density);
    //   }
    // double inbound_heat_flux
    //   =boundary_condition
    //   .get_inbound_heat_flux(local_surface_type,
    // 			     local_author,
    // 			     override_shading_factor,
    // 			     new_canopy_temperature,
    // 			     canopy_density,
    // 			     old_surface_temperature,
    // 			     tav_surface_temperature,
    // 			     true);
    // boundary_condition
    //   .print_inbound_heat_fluxes(solar_heat_flux,
    // 				 inbound_convective_heat_flux,
    // 				 inbound_evaporative_heat_flux,
    // 				 inbound_infrared_heat_flux,
    // 				 outbound_convective_coefficient,
    // 				 outbound_infrared_coefficient,
    // 				 outbound_evaporative_coefficient);
    // outbound_convective_coefficient
    //   =boundary_condition
    //   .get_outbound_coefficient(local_surface_type,
    // 				local_author,
    // 				canopy_density,
    // 				old_surface_temperature,
    // 				tav_surface_temperature,
    // 				true);
    
    // cell_index_to_new_outbound_coefficient[cell]
    //   =outbound_convective_coefficient_new;
    // cell_index_to_new_inbound_flux[cell]
    //   =inbound_heat_flux_new;

    // return inbound_heat_flux;
    return 0.;
  }
  
  template <int dim>
  void BoundaryFlux<dim>::value_list(const std::vector<Point<dim> > &points,
				      std::vector<double> &values,
				      const unsigned int  component) const
  {
    const unsigned int n_points = points.size();
    Assert (values.size() == n_points,
	    ExcDimensionMismatch (values.size(), n_points));
    Assert (component == 0,
	    ExcIndexRange (component, 0, 1));
    for (unsigned int i=0; i<n_points; ++i)
      {
	values[i] = 100;
      }
  }


  template <int dim>
  class Heat_Pipe
  {
  public:
    Heat_Pipe(int argc, char *argv[]);
    ~Heat_Pipe();
    void run();
  private:
    void output_results();
    void fill_output_vectors();
    void update_met_data();

    void read_mesh();
    void refine_grid();
    void initial_condition();
    void setup_system();
    void assemble_system_petsc();
    void assemble_system_parallel(bool system_switch,
				  unsigned int iteration);
    unsigned int solve();

    void surface_temperatures();
    void mesh_info();
    std::string find_material(const unsigned int material_id);

    parallel::shared::Triangulation<dim>   triangulation;
    FE_Q<dim>            fe;
    DoFHandler<dim>      dof_handler;
    ConstraintMatrix     constraints;
    PETScWrappers::MPI::SparseMatrix system_matrix;
    PETScWrappers::MPI::SparseMatrix mass_matrix;
    PETScWrappers::MPI::SparseMatrix laplace_matrix_new;
    PETScWrappers::MPI::SparseMatrix laplace_matrix_old;
    PETScWrappers::MPI::Vector       system_rhs;
    PETScWrappers::MPI::Vector       solution,old_solution;
    std::vector<types::global_dof_index> local_dofs_per_process;

    MPI_Comm mpi_communicator;
    const unsigned int n_mpi_processes;
    const unsigned int this_mpi_process;
    ConditionalOStream pcout;
    unsigned int n_local_cells;

    IndexSet locally_owned_dofs;
    IndexSet locally_relevant_dofs;

    unsigned int timestep_number_max;
    unsigned int timestep_number;
    double time;
    double time_max;
    double theta;
    double time_step;

    std::string met_data_type;
    std::string activation_type;
    double canopy_density;
    const bool moisture_movement;
    //
    std::string author;
    std::string preheating_output_filename;
    std::string preheating_input_filename;
    std::string input_path;
    std::string output_path;
    std::string mesh_path;
    bool fixed_bc_at_bottom;
    bool pipe_system;
    //bool shading;
    bool insulation;
    bool analytic_met_data;
    int  preheating_step;
    double shading_factor_value;
    double thermal_conductivity_factor;
    int type_of_weather;

    const unsigned int number_of_pipes;//=40;
    /*----------------------mesh data vectors--------------------*/
    std::map<typename DoFHandler<dim>::active_cell_iterator,unsigned int >
    cell_index_to_face_index,  // relate cells at boundary with corresponding face at boundary
      cell_index_to_mpi_process, // to distribute calculations on boundary cells on all mpi processes
      cell_index_to_pipe_number; // relate boundary cells on pipes with its pipe number (0-19)
    std::map<typename DoFHandler<dim>::active_cell_iterator,double >
    cell_index_to_old_surface_temperature,
      cell_index_to_current__new_surface_temperature,
      cell_index_to_previous_new_surface_temperature,
      cell_index_to_old_outbound_coefficient,
      cell_index_to_new_outbound_coefficient,
      cell_index_to_old_inbound_flux,
      cell_index_to_new_inbound_flux;

    std::map<typename DoFHandler<dim>::active_cell_iterator,std::vector<double>>
    cell_index_to_old_boundary_coefficient_and_fluxes_road,
      cell_index_to_old_boundary_coefficient_and_fluxes_soil,
      cell_index_to_new_boundary_coefficient_and_fluxes_road,
      cell_index_to_new_boundary_coefficient_and_fluxes_soil;

    std::map<unsigned int, std::string> map_material_id_to_material_name
    ={
      { 8,"wearing_course"},
      { 9,"binder_course"},
      {10,"concrete"},
      {11,"concrete"},
      {12,"clay_trl"},
      {13,"clay_trl"},
      {14,"clay_trl"},
    };
    /*-------------met data vectors and variables----------------*/
      std::vector< std::vector<int> >    date_and_time;
    std::vector< std::vector<double> > met_data;
    std::vector<int> initial_date;
    double new_air_temperature,old_air_temperature;
    double new_relative_humidity,old_relative_humidity;
    double new_wind_speed,old_wind_speed;
    double new_wind_direction,old_wind_direction;
    double new_solar_radiation,old_solar_radiation;
    double new_precipitation,old_precipitation;

    const unsigned int n_boundary_ids;//=8;
    const unsigned int boundary_id_collector;//=1;
    const unsigned int boundary_id_storage;//=2;
    const unsigned int boundary_id_road;//=3;
    const unsigned int boundary_id_soil;//=4;
    const unsigned int boundary_id_soil_bottom;//=5;

    //    /*--------------pipe system vectors and variables--------------*/
    std::vector<double> max_pipe_temperature;
    std::vector<double> new_avg_pipe_temperature;
    std::vector<double> min_pipe_temperature;
    std::vector<int> cell_faces_per_pipe;
    std::vector<double> old_avg_pipe_temperature;
    //
    std::vector<double> old_pipe_heat_flux;
    std::vector<double> current__new_pipe_heat_flux;
    //
    double old_avg_soil_surface_temperature;
    double old_avg_road_surface_temperature;
    //
    double previous_new_avg_soil_surface_temperature;
    double previous_new_avg_road_surface_temperature;
    double previous_new_max_soil_surface_temperature;
    double previous_new_min_soil_surface_temperature;
    double previous_new_max_road_surface_temperature;
    double previous_new_min_road_surface_temperature;

    double current_new_avg_soil_surface_temperature;
    double current_new_avg_road_surface_temperature;
    //
    //    const double collector_depth;//=0.1325;
    //    const double storage_depth;//  =0.8475;
    //    /*------------ vectors for output data --------------*/
    const unsigned int number_of_surface_heat_and_mass_fluxes;//=11;
    //    //static const Point<dim> stores_centers[2];
    Point<dim> borehole_A_depths[35];
    Point<dim> borehole_F_depths[35];
    Point<dim> borehole_H_depths[35];
    Point<dim> borehole_I_depths[35];
    //
    //    std::vector< std::vector<int> > date_and_time_1d;
    //
    std::vector< std::vector<double> > soil_bha_temperature;
    std::vector< std::vector<double> > soil_bhf_temperature;
    std::vector< std::vector<double> > soil_bhh_temperature;
    std::vector< std::vector<double> > soil_bhi_temperature;
    std::vector< std::vector<double> > pipe_heat_fluxes;
    std::vector< std::vector<double> > control_temperatures;
    //
    std::vector< std::vector<double> > road_heat_fluxes;
    std::vector< std::vector<double> > soil_heat_fluxes;
    
    static std::string author_options[3];
    static std::string weather_options[6];

    Parameters::AllParameters<dim>  parameters;

    //std::map<unsigned int,std::string> boundary_id_map;


  };
  /*
   * amd: analytical meteorological data
   * emd: experimental meteorological data
   */
  template<int dim>
  std::string Heat_Pipe<dim>::weather_options[6]={
    "amd-mild-1","amd-mild-2","amd-cold",
		  "amd-hot","emd-trl","emd-badc"};
  
  template<int dim>
  Heat_Pipe<dim>::Heat_Pipe (int argc, char *argv[])
    :
  triangulation    (MPI_COMM_WORLD),
  fe               (1),
  dof_handler      (triangulation),
  mpi_communicator (MPI_COMM_WORLD),
  n_mpi_processes  (Utilities::MPI::n_mpi_processes(mpi_communicator)),
  this_mpi_process (Utilities::MPI::this_mpi_process(mpi_communicator)),
  pcout            (std::cout,(this_mpi_process==0)),
  n_local_cells    (numbers::invalid_unsigned_int),
  moisture_movement(false),
  number_of_pipes  (40),
  n_boundary_ids          (8),
  boundary_id_collector   (1),
  boundary_id_storage     (2),
  boundary_id_road        (3),
  boundary_id_soil        (4),
  boundary_id_soil_bottom (5),
  max_pipe_temperature       (number_of_pipes,-1.e6),
  new_avg_pipe_temperature   (number_of_pipes,0.),
  min_pipe_temperature       (number_of_pipes,1.e6),
  cell_faces_per_pipe        (number_of_pipes,0),
  old_avg_pipe_temperature   (number_of_pipes,0.),
  old_pipe_heat_flux         (number_of_pipes,0),
  current__new_pipe_heat_flux(number_of_pipes,0),
  number_of_surface_heat_and_mass_fluxes(10),
  control_temperatures(1,std::vector<double>(2)),
  road_heat_fluxes(1,std::vector<double>(number_of_surface_heat_and_mass_fluxes)),
  soil_heat_fluxes(1,std::vector<double>(number_of_surface_heat_and_mass_fluxes))
  {
    if (argc!=2)
      {
	pcout << "Error. The program expects only one argument, the "
	  "name of the file with the input parameters.\n";
	throw 1;
      }
    const std::string input_filename = argv[1];
    pcout << "parameter file: " << input_filename << "\n";
    std::ifstream inFile;
    inFile.open(input_filename.c_str());

    ParameterHandler prm;
    Parameters::AllParameters<dim>::declare_parameters (prm);
    prm.parse_input(inFile,input_filename);
    parameters.parse_parameters (prm);

    theta   =parameters.theta;
    time_step           =parameters.time_step;
    canopy_density      =parameters.canopy_density;
    author              =parameters.author;
    preheating_step     =parameters.preheating_step;
    fixed_bc_at_bottom  =parameters.fixed_bc_at_bottom;
    insulation          =parameters.with_insulation;
    pipe_system         =parameters.with_pipe_system;
    shading_factor_value=parameters.shading_factor;
    thermal_conductivity_factor=parameters.thermal_conductivity_factor;
    input_path          =parameters.input_path;
    output_path         =parameters.output_path;
    std::string type_of_weather_str=parameters.weather_type;
    mesh_path=input_path+"/"+parameters.mesh_dirname+"/"+parameters.mesh_filename;
    activation_type     =parameters.activation_type;
    
    if (strcmp(type_of_weather_str.c_str(),weather_options[0].c_str())==0)
      {
	analytic_met_data=true;
	type_of_weather=1;
	met_data_type="";
      }
    else if (strcmp(type_of_weather_str.c_str(),weather_options[1].c_str())==0)
      {
	analytic_met_data=true;
	type_of_weather=2;
	met_data_type="";
      }
    else if (strcmp(type_of_weather_str.c_str(),weather_options[2].c_str())==0)
      {
	analytic_met_data=true;
	type_of_weather=3;
	met_data_type="";
      }
    else if (strcmp(type_of_weather_str.c_str(),weather_options[3].c_str())==0)
      {
	analytic_met_data=true;
	type_of_weather=4;
	met_data_type="";
      }
    else if (strcmp(type_of_weather_str.c_str(),weather_options[4].c_str())==0)
      {
	analytic_met_data=false;
	type_of_weather=-1;
	met_data_type="trl_met_data";
      }
    else if (strcmp(type_of_weather_str.c_str(),weather_options[5].c_str())==0)
      {
	analytic_met_data=false;
	type_of_weather=-1;
	met_data_type="met_office_data";
      }
    else
      {
	pcout << "Error. Wrong type of weather.\n";
	throw -1;
      }

    std::stringstream out_phs;
    out_phs << author << "_ph" << preheating_step << "_2d_"
	    << "ws_" << shading_factor_value << "_"
	    << "kf_" << thermal_conductivity_factor << "_"
	    << type_of_weather_str << "_";
    std::stringstream in_phs;
    in_phs << author << "_ph" << preheating_step-1 << "_2d_"
	   << "ws_" << shading_factor_value << "_"
	   << "kf_" << thermal_conductivity_factor << "_"
	   << type_of_weather_str << "_";

    if (fixed_bc_at_bottom==true)
      {
	out_phs << "fx";
	in_phs  << "fx";
      }
    else
      {
	out_phs << "fr";
	in_phs  << "fr";
      }

    preheating_output_filename=out_phs.str();
    preheating_input_filename=in_phs.str();

    time=0.;
    timestep_number=0;
    timestep_number_max=0;
    if (preheating_step==1 && time_step==3600)
      {
	time_step=3600;
	timestep_number_max=4300;//70079; // 8 years
	initial_date.reserve(6);
	initial_date.push_back(1);
	initial_date.push_back(9);
	initial_date.push_back(1994);
	initial_date.push_back(0);
	initial_date.push_back(30);
	initial_date.push_back(0);
      }
    else if (preheating_step==2 && time_step==3600)
      {
	timestep_number_max=5804;
	initial_date.reserve(6);
	initial_date.push_back(1);
	initial_date.push_back(9);
	initial_date.push_back(2004);
	initial_date.push_back(0);
	initial_date.push_back(30);
	initial_date.push_back(0);
      }
    else if (preheating_step==3 && time_step==3600)
      {
	timestep_number_max=2735;
	initial_date.reserve(6);
	initial_date.push_back(1);
	initial_date.push_back(5);
	initial_date.push_back(2005);
	initial_date.push_back(0);
	initial_date.push_back(30);
	initial_date.push_back(0);
      }
    else if (preheating_step==4)
      {
	time_step=900;
	timestep_number_max=7964;
	initial_date.reserve(6);
	initial_date.push_back(23);
	initial_date.push_back(8);
	initial_date.push_back(2005);
	initial_date.push_back(0);
	initial_date.push_back(30);
	initial_date.push_back(0);
      }
    else if (preheating_step==5)
      {
	time_step=900;
	timestep_number_max=9500;
	initial_date.reserve(6);
	initial_date.push_back(14);
	initial_date.push_back(11);
	initial_date.push_back(2005);
	initial_date.push_back(0);
	initial_date.push_back(30);
	initial_date.push_back(0);
      }
    else if (preheating_step==6)
      {
	time_step=3600;
	timestep_number_max=1559;
	initial_date.reserve(6);
	initial_date.push_back(21);
	initial_date.push_back(2);
	initial_date.push_back(2006);
	initial_date.push_back(0);
	initial_date.push_back(30);
	initial_date.push_back(0);
      }
    else if (preheating_step==7)
      {
	time_step=900;
	timestep_number_max=18044;
	initial_date.reserve(6);
	initial_date.push_back(27);
	initial_date.push_back(4);
	initial_date.push_back(2006);
	initial_date.push_back(0);
	initial_date.push_back(30);
	initial_date.push_back(0);
      }
    else if (preheating_step==8)
      {
	time_step=900;
	timestep_number_max=11516;
	initial_date.reserve(6);
	initial_date.push_back(1);
	initial_date.push_back(11);
	initial_date.push_back(2006);
	initial_date.push_back(0);
	initial_date.push_back(30);
	initial_date.push_back(0);
      }
    else
      {
	pcout << "Wrong preheating step and/or time step\n";
	throw -1;
      }
    time_max=time_step*timestep_number_max;


    pcout << "Solving problem with the following data:\n"
	  << "\tAuthor: " << author << "\n"
	  << "\tpreheating_step: " << preheating_step << "\n"
	  << "\ttime step: " << time_step << "\n"
	  << "\tshading factor: " << shading_factor_value << "\n"
	  << "\tbottom_bc: ";
    if (fixed_bc_at_bottom==true)
      pcout << "true\n";
    else
      pcout << "false\n";

    pcout << "\tinsulation: ";
    if (insulation==true)
      pcout << "true\n";
    else
      pcout << "false\n";

    pcout << "\tpipe_system: ";
    if (pipe_system==true)
      pcout << "true\n";
    else
      pcout << "false\n";

    pcout << "\tOutput preheating file: " << preheating_output_filename << "\n";
    if (preheating_step>1)
      pcout << "\tInput preheating file : " << preheating_input_filename << "\n";
    else
      pcout << "No input preheating file defined\n";
    /*
     * Check if files and directories exist
     */
    DataTools data_tools;
    if (data_tools.file_exists(mesh_path)==false)
      {
	pcout << "Error file: " << mesh_path << " does not exists!\n";
	throw -1;
      }
    else
      {
	pcout << "Reading mesh from: " << mesh_path << std::endl;
      }

    if (!data_tools.dir_exists(input_path))
      {
	std::cout << "Error directory: " << input_path << "doesn't exists!\n";
	throw -1;
      }
    else
      pcout << "Input path: " << input_path << std::endl;

    if (!data_tools.dir_exists(output_path))
      {
	std::cout << "Error directory: " << output_path << " doesn't exists!\n";
	throw -1;
      }
    else
      {
	pcout << "Output path: " << output_path << std::endl;
      }
    /*
     * Initialize vectors that will contain the
     *  sensor depths at boreholes of interest.
     */
    Names names(input_path);
    std::vector<double> borehole_depths;
    names.get_depths(borehole_depths,
		     "road");
    if ((sizeof borehole_A_depths)/(sizeof borehole_A_depths[0])<borehole_depths.size())
      {
	pcout << "Not enough points for borehole depths definition" << std::endl;
	throw 1;
      }
    for (unsigned int i=0; i<borehole_depths.size(); i++)
      {
	borehole_A_depths[i][0]= 14.5;
	borehole_A_depths[i][1]= -1.*borehole_depths[i];

	borehole_F_depths[i][0]=  0.0;
	borehole_F_depths[i][1]= -1.*borehole_depths[i];

	borehole_H_depths[i][0]=  2.5;
	borehole_H_depths[i][1]= -1.*borehole_depths[i];

	borehole_I_depths[i][0]=  5.0;
	borehole_I_depths[i][1]= -1.*borehole_depths[i];
      }

    new_air_temperature=0.;
    old_air_temperature=0.;
    new_relative_humidity=0.;
    old_relative_humidity=0.;
    new_wind_speed=0.;
    old_wind_speed=0.;
    new_wind_direction=0.;
    old_wind_direction=0.;
    new_solar_radiation=0.;
    old_solar_radiation=0.;
    new_precipitation=0.;
    old_precipitation=0.;

    old_avg_soil_surface_temperature=10.;
    old_avg_road_surface_temperature=10.;

    previous_new_avg_soil_surface_temperature=10.;
    previous_new_avg_road_surface_temperature=10.;
    previous_new_max_soil_surface_temperature=10.;
    previous_new_min_soil_surface_temperature=10.;
    previous_new_max_road_surface_temperature=10.;
    previous_new_min_road_surface_temperature=10.;

    current_new_avg_soil_surface_temperature=10.;
    current_new_avg_road_surface_temperature=10.;
  }
  
  template<int dim>
  Heat_Pipe<dim>::~Heat_Pipe ()
  {
	  dof_handler.clear ();
  }

  template<int dim>
  void Heat_Pipe<dim>::read_mesh()
  {
	  GridIn<dim> grid_in;
	  grid_in.attach_triangulation(triangulation);
	  std::ifstream file (mesh_path.c_str());
	  grid_in.read_msh (file);
  }

  template <int dim>
  void Heat_Pipe<dim>::refine_grid ()
  {
	  typename Triangulation<dim>::active_cell_iterator
	  cell = triangulation.begin_active(),
	  endc = triangulation.end();
	  for (; cell!=endc; ++cell)
	  {
		  //if (cell->material_id()==10)
		  double x=cell->center()[0];
		  double y=cell->center()[1];
		  double m=(-2.6737-0.)/(-7.8196+4.);
		  if ((x<14.8 && x>-7.8196 && y>-0.2) ||
				  (x<-7.8196 && x>-12.8196 && y>-2.8737) ||
				  (x<-4.     && x> -7.8196
						  && y>m*(x+7.8196)-2.6737-0.2))
			  cell->set_refine_flag();
	  }

	  SolutionTransfer< dim,Vector<double> > solution_transfer(dof_handler);

	  std::vector<Vector<double> > transfer_in(2);
	  transfer_in[0]=old_solution;
	  transfer_in[1]=    solution;

	  triangulation
	  .prepare_coarsening_and_refinement();
	  solution_transfer
	  .prepare_for_coarsening_and_refinement(transfer_in);

	  triangulation
	  .execute_coarsening_and_refinement();
	  dof_handler.distribute_dofs(fe);

	  setup_system();

	  std::vector<Vector<double> > transfer_out(2);
	  transfer_out[0].reinit(dof_handler.n_dofs());
	  transfer_out[1].reinit(dof_handler.n_dofs());

	  solution_transfer.interpolate (transfer_in, transfer_out);

	  old_solution=transfer_out[0];
	  solution=transfer_out[1];
  }

  template <int dim>
  std::string Heat_Pipe<dim>::find_material(const unsigned int material_id)
  {
    std::map<unsigned int, std::string>::iterator
      it=map_material_id_to_material_name.find(material_id);
    if (it!=map_material_id_to_material_name.end())
      return it->second;
    else
      {
	std::cout << "MPI process " << this_mpi_process
		  << " found an error. Material id "
		  << material_id << " not found.\n";
	throw -1;
      }
  }
  
  template<int dim>
  void Heat_Pipe<dim>::setup_system()
  {
	  dof_handler.distribute_dofs(fe);
	  locally_owned_dofs = dof_handler.locally_owned_dofs();
	  DoFTools::extract_locally_relevant_dofs (dof_handler,locally_relevant_dofs);
	  n_local_cells
	  = GridTools::count_cells_with_subdomain_association (triangulation,
			  triangulation.locally_owned_subdomain ());

	  local_dofs_per_process = dof_handler.n_locally_owned_dofs_per_processor();

	  constraints.clear();
	  DoFTools::make_hanging_node_constraints(dof_handler,constraints);
	  constraints.close();

	  DynamicSparsityPattern sparsity_pattern(locally_relevant_dofs);
	  DoFTools::make_sparsity_pattern(dof_handler,sparsity_pattern,constraints,/*keep constrained dofs*/false);
	  SparsityTools::distribute_sparsity_pattern (sparsity_pattern,local_dofs_per_process,
			  mpi_communicator,locally_relevant_dofs);

	  old_solution
	  .reinit(locally_owned_dofs,mpi_communicator);
	  solution
	  .reinit(locally_owned_dofs,mpi_communicator);
	  system_rhs
	  .reinit(locally_owned_dofs,mpi_communicator);

	  system_matrix
	  .reinit(locally_owned_dofs,
			  locally_owned_dofs,
			  sparsity_pattern,
			  mpi_communicator);
	  mass_matrix
	  .reinit(locally_owned_dofs,
			  locally_owned_dofs,
			  sparsity_pattern,
			  mpi_communicator);
	  laplace_matrix_new
	  .reinit(locally_owned_dofs,
			  locally_owned_dofs,
			  sparsity_pattern,
			  mpi_communicator);
	  laplace_matrix_old
	  .reinit(locally_owned_dofs,
			  locally_owned_dofs,
			  sparsity_pattern,
			  mpi_communicator);
  }

  template<int dim>
  void Heat_Pipe<dim>::assemble_system_petsc()
  {
	  PETScWrappers::MPI::Vector tmp;
	  tmp.reinit(solution);

	  laplace_matrix_old.vmult(tmp,old_solution);
	  tmp.compress(VectorOperation::insert);
	  tmp*=-(1.-theta)*time_step;
	  tmp.compress(VectorOperation::insert);

	  system_rhs+=tmp;
	  system_rhs.compress(VectorOperation::add);

	  mass_matrix.vmult(tmp,old_solution);
	  tmp.compress(VectorOperation::insert);

	  system_rhs+=tmp;
	  system_rhs.compress(VectorOperation::add);

	  system_matrix = 0.;
	  system_matrix.compress(VectorOperation::insert);
	  system_matrix.add(1.0,mass_matrix);
	  system_matrix.compress(VectorOperation::add);

	  system_matrix.add(theta*time_step,laplace_matrix_new);
	  system_matrix.compress(VectorOperation::add);

	  if (fixed_bc_at_bottom)
	  {
		  std::map<unsigned int,double> boundary_values;
		  VectorTools::interpolate_boundary_values (dof_handler,
				  boundary_id_soil_bottom,
				  ConstantFunction<dim>(10.95),
				  boundary_values);
		  MatrixTools::apply_boundary_values (boundary_values,
				  system_matrix,
				  solution,
				  system_rhs,
				  false);
	  }
	  if (author=="Fixed")
	  {
		  std::map<unsigned int,double> boundary_values;
		  VectorTools::interpolate_boundary_values (dof_handler,
				  boundary_id_road,
				  ConstantFunction<dim>(new_air_temperature),
				  boundary_values);
		  MatrixTools::apply_boundary_values (boundary_values,
				  system_matrix,
				  solution,
				  system_rhs,
				  false);
		  boundary_values.clear();
		  VectorTools::interpolate_boundary_values (dof_handler,
				  boundary_id_soil,
				  ConstantFunction<dim>(new_air_temperature),
				  boundary_values);
		  MatrixTools::apply_boundary_values (boundary_values,
				  system_matrix,
				  solution,
				  system_rhs,
				  false);
	  }
  }

  template<int dim>
  void Heat_Pipe<dim>::assemble_system_parallel(bool system_switch,
						unsigned int iteration)
  {
    mass_matrix       =0.;
    laplace_matrix_new=0.;
    laplace_matrix_old=0.;
    system_rhs        =0.;
    mass_matrix.compress       (VectorOperation::insert);
    laplace_matrix_new.compress(VectorOperation::insert);
    laplace_matrix_old.compress(VectorOperation::insert);
    system_rhs.compress        (VectorOperation::insert);

    const QGauss<dim> quadrature_formula(3);
    const QGauss<dim-1> face_quadrature_formula(3);
    FEValues<dim> fe_values(fe, quadrature_formula,
			    update_values | update_gradients |
			    update_quadrature_points | update_JxW_values);
    FEFaceValues<dim> fe_face_values(fe, face_quadrature_formula,
				     update_values | update_gradients |
				     update_quadrature_points | update_JxW_values);
    const unsigned int dofs_per_cell=fe.dofs_per_cell;
    const unsigned int n_q_points=quadrature_formula.size();
    const unsigned int n_face_q_points=face_quadrature_formula.size ();

    FullMatrix<double> cell_mass_matrix       (dofs_per_cell,dofs_per_cell);
    FullMatrix<double> cell_laplace_matrix_new(dofs_per_cell,dofs_per_cell);
    FullMatrix<double> cell_laplace_matrix_old(dofs_per_cell,dofs_per_cell);
    Vector<double>     cell_rhs               (dofs_per_cell);

    std::vector<unsigned int> local_dof_indices (dofs_per_cell);
    //std::vector<double> boundary_flux_values(n_face_q_points);
    const Vector<double> localized_old_solution(old_solution);
    const Vector<double> localized_new_solution(solution);

    double face_boundary_indicator;

    unsigned int faces_on_road_surface = 0;
    unsigned int faces_on_soil_surface = 0;

    typename DoFHandler<dim>::active_cell_iterator
      cell = dof_handler.begin_active(),
      endc = dof_handler.end();
    for (; cell!=endc; ++cell)
      if (cell->subdomain_id()==this_mpi_process)
	{
	  fe_values.reinit(cell);

	  cell_mass_matrix=0.;
	  cell_laplace_matrix_new=0.;
	  cell_laplace_matrix_old=0.;
	  cell_rhs=0.;

	  Material material(find_material(cell->material_id()));
	  double thermal_conductivity=material.thermal_conductivity();
	  double volumetric_heat_capacity=material.volumetric_heat_capacity();
	  
	  //MaterialData material_data(dim,insulation,0,moisture_movement);
	  //double thermal_conductivity=material_data.get_soil_thermal_conductivity(cell->material_id());
	  //double thermal_heat_capacity=material_data.get_soil_heat_capacity(cell->material_id());
	  //double density=material_data.get_soil_density(cell->material_id());

	  for (unsigned int q_point=0; q_point<n_q_points; ++q_point)
	    for (unsigned int i=0; i<dofs_per_cell; ++i)
	      for (unsigned int j=0; j<dofs_per_cell; ++j)
		{
		  cell_mass_matrix(i,j)+=
		    //thermal_heat_capacity*density*
		    volumetric_heat_capacity*
		    fe_values.shape_value(i,q_point)*
		    fe_values.shape_value(j,q_point)*
		    fe_values.JxW(q_point);
		  cell_laplace_matrix_new(i,j)+=
		    thermal_conductivity*
		    fe_values.shape_grad(i,q_point) *
		    fe_values.shape_grad(j,q_point) *
		    fe_values.JxW(q_point);
		  cell_laplace_matrix_old(i,j)+=
		    thermal_conductivity *
		    fe_values.shape_grad(i,q_point) *
		    fe_values.shape_grad(j,q_point) *
		    fe_values.JxW(q_point);
		}
	  /*
	   * We enter the next section if we found a cell face that represents a boundary.
	   * Then we will calculate the corresponding heat flux according to the
	   * boundary we found. For the case of the pipe boundaries, it is also
	   * necessary for the pipe system to be active. If it isn't then we do nothing
	   * for these cells. This would correspond to a homogeneous boundary condition
	   * of second kind (i.e. insulation)
	   */
	  for (unsigned int face=0; face<GeometryInfo<dim>::faces_per_cell; ++face)
	    {
	      face_boundary_indicator = cell->face(face)->boundary_id();
	      if ((cell->face(face)->at_boundary()) &&
		  (((author!="Fixed") &&
		    ((face_boundary_indicator==boundary_id_road) ||
		     (face_boundary_indicator==boundary_id_soil))) ||
		   ((pipe_system==true) && (system_switch==true) &&
		    ((face_boundary_indicator==boundary_id_collector) ||
		     (face_boundary_indicator==boundary_id_storage  )))))
		{
		  /*
		   * Variables for heat flux from surface. The convective coefficients below
		   * include both convective and infrared interactions since they can be
		   * represented in a similar way (after the radiative coefficients have
		   * been linearized).
		   */
		  double outbound_convective_coefficient_new=0.;
		  double outbound_convective_coefficient_old=0.;
		  double inbound_heat_flux_new=0.;
		  double inbound_heat_flux_old=0.;

		  if ((face_boundary_indicator==boundary_id_road) ||
		      (face_boundary_indicator==boundary_id_soil))
		    {
		      /*
		       * If 'analytic == true' then the remaining variables passed to the object of
		       * class type 'BoundaryConditions' are irrelevant because they are redefined
		       * when its flux members are called according to the 'time' provided.
		       *
		       * Some of the heat transfer coefficients (infrared coefficients in particular)
		       * depend on an estimation of the previous surface temperature. At the beggining
		       * i thought it would be ok to just ask the point_value at each cell. The problem
		       * is that this operation is highly costly (as it needs to iterate and interpolate
		       * in the solution vector) and the cost is directly proportional to the number of
		       * cells (making it unsuitable for 3D). So, a new strategy is needed.
		       */
		      double cell_face_diameter=cell->face(face)->diameter();
		      double old_surface_temperature
			=VectorTools::point_value(dof_handler,
						  localized_old_solution,
						  cell->face(face)->center());
		      double new_surface_temperature=0.;
		      if (timestep_number==1 && iteration==0)
			new_surface_temperature
			  =old_surface_temperature;
		      else
			new_surface_temperature
			  =VectorTools::point_value(dof_handler,
						    localized_new_solution,
						    cell->face(face)->center());
		      /*
		       * Heat flux from soil surface or road surface
		       * */
		      if ((author=="Herb"   ) ||
		      	  (author=="Jansson") ||
		      	  (author=="Best"   ))
		      	{
			  double override_shading_factor=0.;
		      	  if (shading_factor_value>0 &&
		      	      ((face_boundary_indicator==boundary_id_road) &&
		      	       (((date_and_time[timestep_number][3]>=12) &&
				 (date_and_time[timestep_number][3]<=16)) ||
		      	  	((date_and_time[timestep_number][3]==17) &&
				 (date_and_time[timestep_number][4]==00)))))
		      	    override_shading_factor=shading_factor_value;

			  std::string local_author=author;
		      	  std::string local_surface_type="soil";
		      	  if ((dim==2 || dim==3) &&
		      	      (face_boundary_indicator==boundary_id_road))
		      	    {
		      	      local_author="Herb";
		      	      local_surface_type="road";
		      	    }
			  //-----------OLD--------------//
			  double old_solar_heat_flux=0.;
			  double old_inbound_convective_heat_flux=0.;
			  double old_inbound_evaporative_heat_flux=0.;
			  double old_inbound_infrared_heat_flux=0.;
			  double old_outbound_convective_coefficient=0.;
			  double old_outbound_infrared_coefficient=0.;
			  double old_outbound_evaporative_coefficient=0.;
			  {
			    if (timestep_number==1)
			      {
				BoundaryConditions boundary_condition_old (false/*analytic*/,
									   time_step*(timestep_number-1),
									   old_air_temperature,
									   old_solar_radiation,
									   old_wind_speed,
									   old_relative_humidity,
									   old_precipitation,
									   old_surface_temperature,
									   0./*,old_surface_pressure*/,
									   moisture_movement);
			  	double old_canopy_temperature=0.;
			  	if (local_author=="Best")
			  	  {
			  	    old_canopy_temperature
			  	      =boundary_condition_old
			  	      .get_canopy_temperature(local_author,
			  				      canopy_density);
			  	  }
			  	outbound_convective_coefficient_old
			  	  =boundary_condition_old
			  	  .get_outbound_coefficient(local_surface_type,
			  				    local_author,
			  				    canopy_density,
			  				    old_surface_temperature,
			  				    old_surface_temperature,
			  				    true);
			  	inbound_heat_flux_old
			  	  =boundary_condition_old
			  	  .get_inbound_heat_flux(local_surface_type,
			  				 local_author,
			  				 override_shading_factor,
			  				 old_canopy_temperature,
			  				 canopy_density,
			  				 old_surface_temperature,
			  				 old_surface_temperature,
			  				 true);
				boundary_condition_old.print_inbound_heat_fluxes(old_solar_heat_flux,
										 old_inbound_convective_heat_flux,
										 old_inbound_evaporative_heat_flux,
										 old_inbound_infrared_heat_flux,
										 old_outbound_convective_coefficient,
										 old_outbound_infrared_coefficient,
										 old_outbound_evaporative_coefficient);
			      }
			    else
			      {
			  	outbound_convective_coefficient_old
			  	  =cell_index_to_old_outbound_coefficient[cell];
			  	inbound_heat_flux_old
			  	  =cell_index_to_old_inbound_flux[cell];

				if (face_boundary_indicator==boundary_id_road)
				  {
				    old_solar_heat_flux
				      =cell_index_to_old_boundary_coefficient_and_fluxes_road[cell][0];
				    old_inbound_convective_heat_flux
				      =cell_index_to_old_boundary_coefficient_and_fluxes_road[cell][1];
				    old_inbound_evaporative_heat_flux
				      =cell_index_to_old_boundary_coefficient_and_fluxes_road[cell][2];
				    old_inbound_infrared_heat_flux
				      =cell_index_to_old_boundary_coefficient_and_fluxes_road[cell][3];
				    old_outbound_convective_coefficient
				      =cell_index_to_old_boundary_coefficient_and_fluxes_road[cell][4];
				    old_outbound_infrared_coefficient
				      =cell_index_to_old_boundary_coefficient_and_fluxes_road[cell][5];
				    old_outbound_evaporative_coefficient
				      =cell_index_to_old_boundary_coefficient_and_fluxes_road[cell][6];
				  }
				else
				  {
				    old_solar_heat_flux
				      =cell_index_to_old_boundary_coefficient_and_fluxes_soil[cell][0];
				    old_inbound_convective_heat_flux
				      =cell_index_to_old_boundary_coefficient_and_fluxes_soil[cell][1];
				    old_inbound_evaporative_heat_flux
				      =cell_index_to_old_boundary_coefficient_and_fluxes_soil[cell][2];
				    old_inbound_infrared_heat_flux
				      =cell_index_to_old_boundary_coefficient_and_fluxes_soil[cell][3];
				    old_outbound_convective_coefficient
				      =cell_index_to_old_boundary_coefficient_and_fluxes_soil[cell][4];
				    old_outbound_infrared_coefficient
				      =cell_index_to_old_boundary_coefficient_and_fluxes_soil[cell][5];
				    old_outbound_evaporative_coefficient
				      =cell_index_to_old_boundary_coefficient_and_fluxes_soil[cell][6];
				  }
			      }
			  }
			  //-----------NEW--------------//
			  double new_solar_heat_flux=0.;
			  double new_inbound_convective_heat_flux=0.;
			  double new_inbound_evaporative_heat_flux=0.;
			  double new_inbound_infrared_heat_flux=0.;
			  double new_outbound_convective_coefficient=0.;
			  double new_outbound_infrared_coefficient=0.;
			  double new_outbound_evaporative_coefficient=0.;
			  {
			    
			    double tav_surface_temperature
			      =1.0*old_surface_temperature+
			      0.0*new_surface_temperature;
			    BoundaryConditions boundary_condition_new (false/*analytic*/,
			  					       time_step*timestep_number,
			  					       new_air_temperature,
			  					       new_solar_radiation,
			  					       new_wind_speed,
			  					       new_relative_humidity,
			  					       new_precipitation,
			  					       tav_surface_temperature,
			  					       0./*,new_surface_pressure*/,
			  					       moisture_movement);
			    double new_canopy_temperature=0.;
			    if (local_author=="Best")
			      {
			  	new_canopy_temperature
			  	  =boundary_condition_new
			  	  .get_canopy_temperature(local_author,
			  				  canopy_density);
			      }
			    outbound_convective_coefficient_new
			      =boundary_condition_new
			      .get_outbound_coefficient(local_surface_type,
			  				local_author,
			  				canopy_density,
			  				old_surface_temperature,
			  				tav_surface_temperature,
			  				true);
			    inbound_heat_flux_new
			      =boundary_condition_new
			      .get_inbound_heat_flux(local_surface_type,
			  			     local_author,
			  			     override_shading_factor,
			  			     new_canopy_temperature,
			  			     canopy_density,
			  			     old_surface_temperature,
			  			     tav_surface_temperature,
			  			     true);

			    cell_index_to_new_outbound_coefficient[cell]
			      =outbound_convective_coefficient_new;
			    cell_index_to_new_inbound_flux[cell]
			      =inbound_heat_flux_new;

			    boundary_condition_new
			      .print_inbound_heat_fluxes(new_solar_heat_flux,
							 new_inbound_convective_heat_flux,
							 new_inbound_evaporative_heat_flux,
							 new_inbound_infrared_heat_flux,
							 new_outbound_convective_coefficient,
							 new_outbound_infrared_coefficient,
							 new_outbound_evaporative_coefficient);
			    
			    if (face_boundary_indicator==boundary_id_road)
			      {
				cell_index_to_new_boundary_coefficient_and_fluxes_road[cell][0]
				  =new_solar_heat_flux;
				cell_index_to_new_boundary_coefficient_and_fluxes_road[cell][1]
				  =new_inbound_convective_heat_flux;
				cell_index_to_new_boundary_coefficient_and_fluxes_road[cell][2]
				  =new_inbound_evaporative_heat_flux;
				cell_index_to_new_boundary_coefficient_and_fluxes_road[cell][3]
				  =new_inbound_infrared_heat_flux;
				cell_index_to_new_boundary_coefficient_and_fluxes_road[cell][4]
				  =new_outbound_convective_coefficient;
				cell_index_to_new_boundary_coefficient_and_fluxes_road[cell][5]
				  =new_outbound_infrared_coefficient;
				cell_index_to_new_boundary_coefficient_and_fluxes_road[cell][6]
				  =new_outbound_evaporative_coefficient;
			      }
			    else
			      {
				cell_index_to_new_boundary_coefficient_and_fluxes_soil[cell][0]
				  =new_solar_heat_flux;
				cell_index_to_new_boundary_coefficient_and_fluxes_soil[cell][1]
				  =new_inbound_convective_heat_flux;
				cell_index_to_new_boundary_coefficient_and_fluxes_soil[cell][2]
				  =new_inbound_evaporative_heat_flux;
				cell_index_to_new_boundary_coefficient_and_fluxes_soil[cell][3]
				  =new_inbound_infrared_heat_flux;
				cell_index_to_new_boundary_coefficient_and_fluxes_soil[cell][4]
				  =new_outbound_convective_coefficient;
				cell_index_to_new_boundary_coefficient_and_fluxes_soil[cell][5]
				  =new_outbound_infrared_coefficient;
				cell_index_to_new_boundary_coefficient_and_fluxes_soil[cell][6]
				  =new_outbound_evaporative_coefficient;
			      }
			  }
		      	  /*
		      	   * Save the calculated heat fluxes.
		      	   */
			  if (face_boundary_indicator==boundary_id_road)
			    {
			      road_heat_fluxes[timestep_number-1][0]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_solar_heat_flux+
				 (1.-theta)*old_solar_heat_flux);
			      road_heat_fluxes[timestep_number-1][1]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_inbound_convective_heat_flux+
				 (1.-theta)*old_inbound_convective_heat_flux);
			      road_heat_fluxes[timestep_number-1][2]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_inbound_evaporative_heat_flux+
				 (1.-theta)*old_inbound_evaporative_heat_flux);
			      road_heat_fluxes[timestep_number-1][3]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_inbound_infrared_heat_flux+
				 (1.-theta)*old_inbound_infrared_heat_flux);
			      road_heat_fluxes[timestep_number-1][4]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_outbound_convective_coefficient*new_surface_temperature+
				 (1.-theta)*old_outbound_convective_coefficient*old_surface_temperature);
			      road_heat_fluxes[timestep_number-1][5]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_outbound_infrared_coefficient*new_surface_temperature+
				 (1.-theta)*old_outbound_infrared_coefficient*old_surface_temperature);
			      road_heat_fluxes[timestep_number-1][6]+=
				theta*new_outbound_convective_coefficient+
				(1.-theta)*old_outbound_convective_coefficient;
			      road_heat_fluxes[timestep_number-1][7]+=
				theta*new_outbound_infrared_coefficient+
				(1.-theta)*old_outbound_infrared_coefficient;
			      road_heat_fluxes[timestep_number-1][8]+=//J/m
				time_step*cell_face_diameter*
				(theta*outbound_convective_coefficient_new*new_surface_temperature+
				 (1.-theta)*outbound_convective_coefficient_old*old_surface_temperature);
			      road_heat_fluxes[timestep_number-1][9]+=//J/m
				time_step*cell_face_diameter*
				(theta*inbound_heat_flux_new+
				 (1.-theta)*inbound_heat_flux_old);
			      faces_on_road_surface++;
			    }
			  else if (face_boundary_indicator==boundary_id_soil)
			    {
			      if (iteration>100 && iteration<=105)
				{
				  std::cout << "\tMPI: " << this_mpi_process
					    << "\ts: " << iteration
					    << "\tcfc: " <<  cell->face(face)->center() << "\n"
					    // << "\tRo : " << old_solar_heat_flux
					    // << "\tRn : " << new_solar_heat_flux << "\n"
					    << "\tICHFo: " << old_inbound_convective_heat_flux
					    << "\tICHFn: " << new_inbound_convective_heat_flux << "\n"
					    << "\tIEHFo: " << old_inbound_evaporative_heat_flux
					    << "\tIEHFn: " << new_inbound_evaporative_heat_flux << "\n"
					    << "\tIIHFo: " << old_inbound_infrared_heat_flux
					    << "\tIIHFn: " << new_inbound_infrared_heat_flux << "\n"
					    << "\tOCCo: " << old_outbound_convective_coefficient
					    << "\tOCCn: " << new_outbound_convective_coefficient << "\n"
					    // << "\tOICo: " << old_outbound_infrared_coefficient
					    // << "\tOICn: " << new_outbound_infrared_coefficient << "\n"
					    << "\tOECo: " << old_outbound_evaporative_coefficient
					    << "\tOECn: " << new_outbound_evaporative_coefficient << "\n\n";
					    // << "\tOCCo: " << outbound_convective_coefficient_old
					    // << "\tOCCn: " << outbound_convective_coefficient_new << "\n"
					    // << "\tIHFo: " << inbound_heat_flux_old
					    // << "\tIHFn: " << inbound_heat_flux_new << "\n\n";
				}
			      
			      soil_heat_fluxes[timestep_number-1][0]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_solar_heat_flux+
				 (1.-theta)*old_solar_heat_flux);
			      soil_heat_fluxes[timestep_number-1][1]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_inbound_convective_heat_flux+
				 (1.-theta)*old_inbound_convective_heat_flux);
			      soil_heat_fluxes[timestep_number-1][2]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_inbound_evaporative_heat_flux+
				 (1.-theta)*old_inbound_evaporative_heat_flux);
			      soil_heat_fluxes[timestep_number-1][3]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_inbound_infrared_heat_flux+
				 (1.-theta)*old_inbound_infrared_heat_flux);
			      soil_heat_fluxes[timestep_number-1][4]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_outbound_convective_coefficient*new_surface_temperature+
				 (1.-theta)*old_outbound_convective_coefficient*old_surface_temperature);
			      soil_heat_fluxes[timestep_number-1][5]+=//J/m
				time_step*cell_face_diameter*
				(theta*new_outbound_infrared_coefficient*new_surface_temperature+
				 (1.-theta)*old_outbound_infrared_coefficient*old_surface_temperature);
			      soil_heat_fluxes[timestep_number-1][6]+=
				theta*new_outbound_convective_coefficient+
				(1.-theta)*old_outbound_convective_coefficient;
			      soil_heat_fluxes[timestep_number-1][7]+=
				theta*new_outbound_infrared_coefficient+
				(1.-theta)*old_outbound_infrared_coefficient;
			      soil_heat_fluxes[timestep_number-1][8]+=//J/m
				time_step*cell_face_diameter*
				(theta*outbound_convective_coefficient_new*new_surface_temperature+
				 (1.-theta)*outbound_convective_coefficient_old*old_surface_temperature);
			      soil_heat_fluxes[timestep_number-1][9]+=//J/m
				time_step*cell_face_diameter*
				(theta*inbound_heat_flux_new+
				 (1.-theta)*inbound_heat_flux_old);				
			      faces_on_soil_surface++;
			    }
			  else
			    {
			      pcout << "Error. face_boundary_id " << face_boundary_indicator << " not implemented.";
			      pcout << std::endl;
			      throw 1;
			    }		      	  
		      	}
		    }
		  // collector and storage pipes in 2D
		  else if ((face_boundary_indicator==boundary_id_collector) ||
			   (face_boundary_indicator==boundary_id_storage))
		    {
		      /*
		       * The heat fluxes are multiplied by -1. because these are
		       * calculated from the point of view of the pipes, so, if
		       * we have a positive value this means a loss of energy from
		       * the soil
		       */
		      //unsigned int pipe_number=cell_index_to_pipe_number[cell];
		      if (face_boundary_indicator==boundary_id_collector)
			{
			  // inbound_heat_flux_old=-1.*old_pipe_heat_flux[pipe_number]/2.59666;//(2.17);
			  // // inbound_heat_flux_new=-1.*(0.5*previous_new_pipe_heat_flux[pipe_number]+
			  // // 			     0.5*current__new_pipe_heat_flux[pipe_number])/(2.17);
			  // inbound_heat_flux_new=-1.*current__new_pipe_heat_flux[pipe_number]/2.59666;//(2.17);
			  inbound_heat_flux_old=0.;
			  inbound_heat_flux_new=0.;
			}
		      else
			{
			  // inbound_heat_flux_old=-1.*old_pipe_heat_flux[pipe_number]/2.59666;//(2.17);//(1.922);
			  // // inbound_heat_flux_new=-1.*(0.5*previous_new_pipe_heat_flux[pipe_number]+
			  // // 			     0.5*current__new_pipe_heat_flux[pipe_number])/(2.17);
			  // inbound_heat_flux_new=-1.*current__new_pipe_heat_flux[pipe_number]/2.59666;//(2.17);
			  inbound_heat_flux_old=0.;
			  inbound_heat_flux_new=0.;
			}
		    }
		  else
		    {
		      pcout << "Error: author not implemented." << std::endl
			    << "Error in assembling function."  << std::endl;
		      throw 3;
		    }

		  fe_face_values.reinit(cell,face);
		  for (unsigned int q_face_point=0; q_face_point<n_face_q_points; ++q_face_point)
		    for (unsigned int i=0; i<dofs_per_cell; ++i)
		      {
			if ((face_boundary_indicator==boundary_id_road) ||
			    (face_boundary_indicator==boundary_id_soil))
			  for (unsigned int j=0; j<dofs_per_cell; ++j)
			    {
			      cell_laplace_matrix_new (i,j)+=
			  	outbound_convective_coefficient_new*
			  	fe_face_values.shape_value(i,q_face_point)*
			  	fe_face_values.shape_value(j,q_face_point)*
			  	fe_face_values.JxW(q_face_point);
			      cell_laplace_matrix_old (i,j)+=
			  	outbound_convective_coefficient_old*
			  	fe_face_values.shape_value(i,q_face_point)*
			  	fe_face_values.shape_value(j,q_face_point)*
			  	fe_face_values.JxW(q_face_point);
			    }
			cell_rhs(i)+=
			  inbound_heat_flux_new*
			  time_step*theta*
			  fe_face_values.shape_value(i,q_face_point)*
			  fe_face_values.JxW(q_face_point)
			  +
			  inbound_heat_flux_old*
			  time_step*(1.-theta)*
			  fe_face_values.shape_value(i,q_face_point)*
			  fe_face_values.JxW(q_face_point);
		      }
		}
	    }
	  cell->get_dof_indices (local_dof_indices);
	  constraints
	    .distribute_local_to_global(cell_laplace_matrix_new,
					local_dof_indices,
					laplace_matrix_new);
	  constraints
	    .distribute_local_to_global(cell_laplace_matrix_old,
					local_dof_indices,
					laplace_matrix_old);
	  constraints
	    .distribute_local_to_global(cell_mass_matrix,
					cell_rhs,
					local_dof_indices,
					mass_matrix, system_rhs);
	}
    laplace_matrix_new.compress(VectorOperation::add);
    laplace_matrix_old.compress(VectorOperation::add);
    mass_matrix.compress(VectorOperation::add);
    system_rhs.compress(VectorOperation::add);
    
    for (unsigned int i=0; i<road_heat_fluxes[timestep_number-1].size(); i++)
      {
	road_heat_fluxes[timestep_number-1][i]=
	  Utilities::MPI::sum(road_heat_fluxes[timestep_number-1][i],mpi_communicator);
	
	soil_heat_fluxes[timestep_number-1][i]=
	  Utilities::MPI::sum(soil_heat_fluxes[timestep_number-1][i],mpi_communicator);
      }
  }

  template<int dim>
  unsigned int Heat_Pipe<dim>::solve()
  {
	  SolverControl solver_control(solution.size(),
			  1e-8*system_rhs.l2_norm());
	  PETScWrappers::SolverCG solver(solver_control,
			  mpi_communicator);
	  PETScWrappers::PreconditionBlockJacobi preconditioner(system_matrix);
	  solver.solve(system_matrix,solution,
			  system_rhs,preconditioner);
	  Vector<double> localized_solution(solution);
	  constraints.distribute(localized_solution);
	  solution=localized_solution;
	  solution.compress(VectorOperation::insert);
	  return solver_control.last_step();
  }

  template<int dim>
  void Heat_Pipe<dim>::output_results()
  {
    const Vector<double> localized_solution (solution);

    DataOut<dim> data_out;
    data_out.attach_dof_handler(dof_handler);
    data_out.add_data_vector(localized_solution,"temperature");
    /*
     * Add information about in which mpi process is each cell being processed
     */
    std::vector<unsigned int> partition_int(triangulation.n_active_cells());
    GridTools::get_subdomain_association(triangulation,partition_int);
    const Vector<double> partitioning (partition_int.begin (),partition_int.end ());
    data_out.add_data_vector (partitioning, "partitioning");
    /*
     * Add information about the material in
     * each cell and its thermal properties
     */    
    //MaterialData material_data (dim,insulation,/*moisture content*/0.23,moisture_movement);
    std::vector<unsigned int> material_id_int;
    std::vector<double> thermal_conductivity_int;
    std::vector<double> specific_heat_capacity_int;
    std::vector<double> density_int;
    std::vector<double> thermal_diffusivity_int;

    std::vector<unsigned int> boundaries;
    typename DoFHandler<dim>::active_cell_iterator
      cell = dof_handler.begin_active(),
      endc = dof_handler.end();
    for (; cell!=endc; ++cell)
      {
	unsigned int material_id=cell->material_id();
	Material material(find_material(material_id));
	material_id_int
	  .push_back(material_id);
	thermal_conductivity_int
	  .push_back(material.thermal_conductivity());
	specific_heat_capacity_int
	  .push_back(material.specific_heat_capacity());
	density_int
	  .push_back(material.density());
	thermal_diffusivity_int
	  .push_back(material.thermal_diffusivity());

	if (cell_index_to_previous_new_surface_temperature.find(cell)!=
	    cell_index_to_previous_new_surface_temperature.end())
	  boundaries.push_back(cell->face(cell_index_to_face_index[cell])->boundary_id());
	else
	  boundaries.push_back(0);
      }
    const Vector<double> material_id           (material_id_int.begin(),
						material_id_int.end());
    const Vector<double> thermal_conductivity  (thermal_conductivity_int.begin(),
						thermal_conductivity_int.end());
    const Vector<double> specific_heat_capacity(specific_heat_capacity_int.begin(),
						specific_heat_capacity_int.end());
    const Vector<double> density               (density_int.begin(),
						density_int.end());
    const Vector<double> thermal_diffusivity   (thermal_diffusivity_int.begin(),
						thermal_diffusivity_int.end());
    const Vector<double> boundary_id           (boundaries.begin(),
						boundaries.end());

    data_out.add_data_vector (material_id           ,"material_id");
    data_out.add_data_vector (thermal_conductivity  ,"thermal_conductivity");
    data_out.add_data_vector (specific_heat_capacity,"specific_heat_capacity");
    data_out.add_data_vector (density               ,"density");
    data_out.add_data_vector (thermal_diffusivity   ,"thermal_diffusivity");
    data_out.add_data_vector (boundary_id   ,"boundary_id");
    /*
     * Define output name
     */
    std::string filename
      = output_path + "/solution-" //+ preheating_output_filename + "-"
      + Utilities::int_to_string(timestep_number,4)
      + "." + Utilities::int_to_string(this_mpi_process, 3)
      + ".vtu";

    data_out.build_patches ();
    std::ofstream output(filename.c_str());
    data_out.write_vtu(output);

    if (this_mpi_process==0)
      {
	std::vector<std::string> filenames;
	for (unsigned int i=0; i<n_mpi_processes; ++i)
	  filenames.push_back ("solution-" //+ preheating_output_filename + "-"
			       + Utilities::int_to_string(timestep_number,4)
			       + "." + Utilities::int_to_string(i,3)
			       + ".vtu");

	const std::string
	  pvtu_master_filename = ("output/solution-" + //+ preheating_output_filename + "-"
				  Utilities::int_to_string(timestep_number,4) + ".pvtu");
	std::ofstream pvtu_master (pvtu_master_filename.c_str());
	data_out.write_pvtu_record (pvtu_master, filenames);

	static std::vector<std::pair<double,std::string> > times_and_names;
	times_and_names.push_back (std::pair<double,std::string> (time-time_step, pvtu_master_filename));
	std::ofstream pvd_output ("solution.pvd");
	DataOutBase::write_pvd_record (pvd_output, times_and_names);
      }

    //	  if (this_mpi_process==0)
    //	  {
    //		  DataOut<dim> data_out;
    //		  data_out.attach_dof_handler (dof_handler);
    //
    //		  std::vector<std::string> solution_names;
    //		  solution_names.push_back ("temperature");
    //
    //		  data_out.add_data_vector (localized_solution,solution_names);
    //		  /*
    //		   * Add information about in which mpi process is each cell being processed
    //		   */
    //		  std::vector<unsigned int>
    //		  partition_int(triangulation.n_active_cells());
    //		  GridTools::get_subdomain_association
    //		  (triangulation, partition_int);
    //		  const Vector<double> partitioning (partition_int.begin (),
    //				  partition_int.end ());
    //		  data_out.add_data_vector (partitioning, "partitioning");
    //		  /*
    //		   * Add information about the material in
    //		   * each cell and its thermal properties
    //		   */
    //		  MaterialData material_data (dim,insulation,/*moisture content*/0.23,moisture_movement);
    //		  std::vector<unsigned int> material_id_int;
    //		  std::vector<double> thermal_conductivity_int;
    //		  std::vector<double> specific_heat_capacity_int;
    //		  std::vector<double> density_int;
    //		  std::vector<double> thermal_diffusivity_int;
    //
    //		  std::vector<unsigned int> boundaries;
    //		  typename DoFHandler<dim>::active_cell_iterator
    //		  cell = dof_handler.begin_active(),
    //		  endc = dof_handler.end();
    //		  for (; cell!=endc; ++cell)
    //		  {
    //			  material_id_int.push_back(cell->material_id());
    //
    //			  if ((cell->center()[0]< 6.0) &&   // insulation edge
    //					  (cell->center()[0]>-6.0) &&   // insulation edge
    //					  (cell->center()[1]<-0.725) && // insulation depth
    //					  (cell->center()[1]>-9.0) &&   // assumed thermal penetration
    //					  (preheating_step>=4) &&
    //					  cell->material_id()==14) // soil material id
    //				  thermal_conductivity_int.push_back(thermal_conductivity_factor*
    //						  material_data.get_soil_thermal_conductivity(cell->material_id()));
    //			  else
    //				  thermal_conductivity_int
    //				  .push_back(material_data.get_soil_thermal_conductivity(cell->material_id()));
    //
    //			  specific_heat_capacity_int
    //			  .push_back(material_data.get_soil_heat_capacity      (cell->material_id()));
    //			  density_int
    //			  .push_back(material_data.get_soil_density            (cell->material_id()));
    //			  thermal_diffusivity_int
    //			  .push_back(material_data.get_soil_thermal_diffusivity(cell->material_id()));
    //
    //			  if (cell_index_to_previous_new_surface_temperature.find(cell)!=
    //					  cell_index_to_previous_new_surface_temperature.end())
    //				  boundaries.push_back(cell->face(cell_index_to_face_index[cell])->boundary_id());
    //			  else
    //				  boundaries.push_back(0);
    //		  }
    //		  const Vector<double> material_id           (material_id_int.begin(),
    //				  material_id_int.end());
    //		  const Vector<double> thermal_conductivity  (thermal_conductivity_int.begin(),
    //				  thermal_conductivity_int.end());
    //		  const Vector<double> specific_heat_capacity(specific_heat_capacity_int.begin(),
    //				  specific_heat_capacity_int.end());
    //		  const Vector<double> density               (density_int.begin(),
    //				  density_int.end());
    //		  const Vector<double> thermal_diffusivity   (thermal_diffusivity_int.begin(),
    //				  thermal_diffusivity_int.end());
    //		  const Vector<double> boundary_id           (boundaries.begin(),
    //				  boundaries.end());
    //
    //		  data_out.add_data_vector (material_id           ,"material_id");
    //		  data_out.add_data_vector (thermal_conductivity  ,"thermal_conductivity");
    //		  data_out.add_data_vector (specific_heat_capacity,"specific_heat_capacity");
    //		  data_out.add_data_vector (density               ,"density");
    //		  data_out.add_data_vector (thermal_diffusivity   ,"thermal_diffusivity");
    //		  data_out.add_data_vector (boundary_id   ,"boundary_id");
    //
    //		    std::stringstream filename;
    //		    filename << output_path << "/solution_" << preheating_output_filename << "_"
    //		    		<< std::setw(5) << std::setfill('0') << timestep_number;
    ////		      << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][2] << "_"
    ////			  << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][1] << "_"
    ////			  << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][0] << "_"
    ////			  << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][3] << "_"
    ////			  << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][4];
    //
    //		  data_out.build_patches ();
    //		  if (dim==1)
    //			  filename << ".gp";
    //		  if (dim==3 || dim==2)
    //			  filename << ".vtu";
    //		  std::ofstream output (filename.str());
    //		  if (dim==1)
    //			  data_out.write_gnuplot (output);
    //		  if (dim==3 || dim==2)
    //			  data_out.write_vtu (output);
    //	  }
  }

  template<int dim>
  void Heat_Pipe<dim>::fill_output_vectors()
  {
    const Vector<double> localized_solution_temperature(old_solution);

    Names names(input_path);
    std::vector<double>borehole_depths;
    names.get_depths(borehole_depths,"road");
    unsigned int soil_depths=borehole_depths.size();
    std::vector<double> soil_bha_temperature_row(soil_depths,0.);
    std::vector<double> soil_bhf_temperature_row(soil_depths,0.);
    std::vector<double> soil_bhh_temperature_row(soil_depths,0.);
    std::vector<double> soil_bhi_temperature_row(soil_depths,0.);

    unsigned int index=0;
    unsigned int depths=0;
    for (unsigned int i=0; i<5*soil_depths; i++)
      {
    	if (i>=n_mpi_processes*(index+1))
	  index++;
    	if (i>=soil_depths*(depths+1))
	  depths++;

    	if (this_mpi_process==(i-index*n_mpi_processes))
	  {
	    if(i<1*soil_depths)
	      soil_bha_temperature_row[i-depths*soil_depths]
		=VectorTools::point_value(dof_handler,
					  localized_solution_temperature,
					  borehole_A_depths[i-soil_depths*depths]);
	    if(i<2*soil_depths && i>=1*soil_depths)
	      soil_bhf_temperature_row[i-depths*soil_depths]
		=VectorTools::point_value(dof_handler,
					  localized_solution_temperature,
					  borehole_F_depths[i-soil_depths*depths]);
	    if(i<3*soil_depths && i>=2*soil_depths)
	      soil_bhh_temperature_row[i-depths*soil_depths]
		=VectorTools::point_value(dof_handler,
					  localized_solution_temperature,
					  borehole_H_depths[i-soil_depths*depths]);
	    if(i<4*soil_depths && i>=3*soil_depths)
	      soil_bhi_temperature_row[i-depths*soil_depths]
		=VectorTools::point_value(dof_handler,
					  localized_solution_temperature,
					  borehole_I_depths[i-soil_depths*depths]);
	  }
      }
    std::vector< std::vector<double> > temp;
    temp.push_back(soil_bha_temperature_row);
    temp.push_back(soil_bhf_temperature_row);
    temp.push_back(soil_bhh_temperature_row);
    temp.push_back(soil_bhi_temperature_row);

    for (unsigned int i=0; i<temp.size(); i++)
      {
    	std::vector<double> temp_row;
    	for (unsigned int j=0; j<temp[i].size(); j++)
	  temp_row.push_back(Utilities::MPI::sum(temp[i][j],mpi_communicator));
    	if (i==0)
	  soil_bha_temperature.push_back(temp_row);
    	if (i==1)
	  soil_bhf_temperature.push_back(temp_row);
    	if (i==2)
	  soil_bhh_temperature.push_back(temp_row);
    	if (i==3)
	  soil_bhi_temperature.push_back(temp_row);
      }
    if (pipe_system==true)
      pipe_heat_fluxes.push_back(current__new_pipe_heat_flux);
  }

  template<int dim>
  void Heat_Pipe<dim>::mesh_info()
  {
    /*
     * Clear all the maps that we need to store the cell data
     */
    cell_index_to_face_index.clear();
    cell_index_to_previous_new_surface_temperature.clear();
    cell_index_to_current__new_surface_temperature.clear();
    cell_index_to_old_surface_temperature.clear();
    cell_index_to_old_outbound_coefficient.clear();
    cell_index_to_new_outbound_coefficient.clear();
    cell_index_to_old_inbound_flux.clear();
    cell_index_to_new_inbound_flux.clear();
    // cell_index_to_old_boundary_coefficient_and_fluxes_road.clear();
    // cell_index_to_old_boundary_coefficient_and_fluxes_soil.clear();
    // cell_index_to_new_boundary_coefficient_and_fluxes_road.clear();
    // cell_index_to_new_boundary_coefficient_and_fluxes_soil.clear();
    //	  cell_index_to_mpi_process.clear();
    //	  cell_index_to_pipe_number.clear();

    std::map<unsigned int,unsigned int> boundary_count;
    for (unsigned int i=0; i<n_boundary_ids; i++)
      boundary_count[i]=0;
    int number_of_local_cells = 0;

    unsigned int mpi_index = 0;
    typename DoFHandler<dim>::active_cell_iterator
      cell = dof_handler.begin_active(),
      endc = dof_handler.end();
    for (; cell!=endc; ++cell)
      for (unsigned int face=0; face<GeometryInfo<dim>::faces_per_cell; ++face)
	if (cell->face(face)->at_boundary())
	  {
	    unsigned int boundary_id
	      =cell->face(face)->boundary_id();
	    Point<dim> cell_center
	      =cell->face(face)->center();
	    /*
	     * We shouldn't have any boundary with 0 indicator index. If
	     * we found any, print it.
	     */
	    if (cell->subdomain_id()==this_mpi_process)
	      number_of_local_cells++;
	    if (boundary_id==0)
	      pcout << cell_center << std::endl;
	    boundary_count[boundary_id]++;

	    if ((boundary_id==boundary_id_road)||
		(boundary_id==boundary_id_soil)||
		((pipe_system==true)&&((boundary_id==boundary_id_collector)||
				       (boundary_id==boundary_id_storage))))
	      {
		cell_index_to_face_index[cell]=face;
		cell_index_to_previous_new_surface_temperature[cell]=18.;
		cell_index_to_current__new_surface_temperature[cell]=18.;
		cell_index_to_old_surface_temperature[cell]=18.;

		
		if ((boundary_id==boundary_id_road)||
		    (boundary_id==boundary_id_soil))
		  {
		    cell_index_to_old_outbound_coefficient[cell]=0.;
		    cell_index_to_new_outbound_coefficient[cell]=0.;
		    cell_index_to_old_inbound_flux[cell]=0.;
		    cell_index_to_new_inbound_flux[cell]=0.;

		    for (unsigned int i=0; i<7; i++)
		      {
			cell_index_to_old_boundary_coefficient_and_fluxes_road[cell].push_back(0.);
			cell_index_to_old_boundary_coefficient_and_fluxes_soil[cell].push_back(0.);
			cell_index_to_new_boundary_coefficient_and_fluxes_road[cell].push_back(0.);
			cell_index_to_new_boundary_coefficient_and_fluxes_soil[cell].push_back(0.);
		      }
		  }
		
		if ((boundary_id==boundary_id_collector)||
		    (boundary_id==boundary_id_storage))
		  {
		    double x=cell_center[0];
		    double y=cell_center[1];
		    double cell_radius=0.;
		    if (((x>0. || x<0.) && dim==3 && (y>12. && y<42.)) ||
			((x>0. || x<0.) && dim==2))
		      cell_radius=fabs(x);
		    else if (y>42. && dim==3)
		      cell_radius=sqrt(pow(fabs(x),2)+pow(y-42.,2));
		    else
		      {
			pcout << "Error in cell: " << cell
			      << " with boundary face center in: "
			      << cell_center << std::endl;
			throw -1;
		      }

		    for (unsigned int i=0; i<10; i++)
		      {
			double r=0.25/2. + (double)i*0.25;
			double dr=0.;
			if (dim==3 && y>42.)
			  dr=r*(1.-cos(22.5*(numbers::PI/180.)));

			if ((dim==3) &&
			    (cell_radius<((r-dr)+0.03)) &&
			    (cell_radius>((r-dr)-0.03)))
			  {
			    if (boundary_id==boundary_id_collector)
			      cell_index_to_pipe_number[cell]=i;
			    else
			      cell_index_to_pipe_number[cell]=i+10;
			    break;
			  }
			if ((dim==2) &&
			    (cell_radius<((r-dr)+0.03)) &&
			    (cell_radius>((r-dr)-0.03)))
			  {
			    if (boundary_id==boundary_id_collector)
			      {
				if (x>0.)
				  cell_index_to_pipe_number[cell]=10+i;
				else
				  cell_index_to_pipe_number[cell]= 9-i;
			      }
			    else
			      {
				if (x>0.)
				  cell_index_to_pipe_number[cell]=30+i;
				else
				  cell_index_to_pipe_number[cell]=29-i;
			      }
			    break;
			  }
		      }
		  }
		if (mpi_index>=n_mpi_processes)
		  mpi_index=0;
		cell_index_to_mpi_process[cell]=mpi_index;
		mpi_index++;
	      }
	  }
    pcout << "\tNumber of mpi processes: "
	  << n_mpi_processes
	  << std::endl;
    pcout << "\t------Mesh info------" << std::endl
	  << "\t dimension..........: " << dim << std::endl
	  << "\t total no. of cells.: " << triangulation.n_active_cells() << std::endl
	  << "\t----Boundary info----" << std::endl
	  << "\t no. of cells (local)..........: " << number_of_local_cells << std::endl
	  << "\t no. of cells (all mpi process): "
	  << Utilities::MPI::sum(number_of_local_cells,mpi_communicator)<< std::endl
	  << "\t-----Misc. info-----" << std::endl
	  << "\t size of solution vectors : "
	  <<     solution.size() << " (new)" << "\t"
	  << old_solution.size() << " (old)" << std::endl;

    pcout << "\tboundary indicators: " << std::endl;

    for (std::map<unsigned int, unsigned int>::iterator
	   it=boundary_count.begin();
	 it!=boundary_count.end(); ++it)
      pcout << "\t" << it->first
	    << "("  << it->second
	    << " times) "
	    << std::endl;
    pcout << std::endl << std::endl;

    // for (typename std::map<typename DoFHandler<dim>::active_cell_iterator,unsigned int >::iterator
    // 	   it=cell_index_to_pipe_number.begin();
    // 	 it!=cell_index_to_pipe_number.end(); ++it)
    //   pcout << it->first << "\t"
    // 	    << it->first->face(cell_index_to_face_index[it->first])->center() << "\t"
    // 	    << it->second << "\n";
    // pcout << std::endl;
  }

  template<int dim>
  void Heat_Pipe<dim>::surface_temperatures()
  {
	  std::vector<double> local_new_surface_temperatures;
	  {
		  const QGauss<dim-1> face_quadrature_formula(3);
		  const unsigned int  n_face_q_points=face_quadrature_formula.size ();
		  std::vector<double> old_face_q_values(n_face_q_points);
		  std::vector<double> new_face_q_values(n_face_q_points);
		  FEFaceValues<dim>   fe_face_values(fe, face_quadrature_formula,
				  update_values | update_gradients |
				  update_quadrature_points | update_JxW_values);
		  const Vector<double> localized_new_solution(solution);
		  /*Calculate temperature*/
		  for (typename std::map<typename DoFHandler<dim>::active_cell_iterator,unsigned int>::iterator
				  it=cell_index_to_face_index.begin();
				  it!=cell_index_to_face_index.end(); ++it)
		  {
			  double new_temperature=0.;
			  if (cell_index_to_mpi_process[it->first]==this_mpi_process)
			  {
				  fe_face_values.reinit(it->first,it->second);
				  fe_face_values.get_function_values(localized_new_solution,new_face_q_values);
				  for (unsigned int q_face_point=0; q_face_point<n_face_q_points; q_face_point++)
					  new_temperature+=new_face_q_values[q_face_point];/*fe_face_values.JxW(q_face_point);*/
				  new_temperature/=n_face_q_points;
			  }
			  local_new_surface_temperatures.push_back(new_temperature);
		  }
	  }
	  {
		  unsigned int vector_index=0;
		  cell_index_to_current__new_surface_temperature.clear();
		  for (typename std::map<typename DoFHandler<dim>::active_cell_iterator,unsigned int>::iterator
				  it=cell_index_to_face_index.begin();
				  it!=cell_index_to_face_index.end(); ++it)
		  {
			  cell_index_to_current__new_surface_temperature[it->first]=
					  Utilities::MPI::sum(local_new_surface_temperatures[vector_index],mpi_communicator);
			  vector_index++;
		  }
	  }
	  /*
	   * Finally, calculate the average surface temperature
	   * AND
	   * Distribute temperatures around pipes
	   */
	  {
		  for (unsigned int i=0; i<number_of_pipes; i++)
		  {
			  max_pipe_temperature[i]=-1.e6;
			  new_avg_pipe_temperature[i]=0.;
			  min_pipe_temperature[i]=1.e6;
			  cell_faces_per_pipe[i]=0;
		  }
		  current_new_avg_soil_surface_temperature=0.;
		  current_new_avg_road_surface_temperature=0.;
		  unsigned int cells_on_soil_surface=0;
		  unsigned int cells_on_road_surface=0;
		  for (typename std::map<typename DoFHandler<dim>::active_cell_iterator,double >::iterator
				  it=cell_index_to_current__new_surface_temperature.begin();
				  it!=cell_index_to_current__new_surface_temperature.end(); ++it)
		  {
			  unsigned int face
			  =cell_index_to_face_index[it->first];
			  unsigned int boundary_id
			  =it->first->face(face)->boundary_id();

			  if (boundary_id==boundary_id_soil)
			  {
				  current_new_avg_soil_surface_temperature
				  +=it->second;
				  cells_on_soil_surface++;
			  }
			  if (boundary_id==boundary_id_road)
			  {
				  current_new_avg_road_surface_temperature
				  +=it->second;
				  cells_on_road_surface++;
			  }
			  if ((boundary_id==boundary_id_collector)||
					  (boundary_id==boundary_id_storage))
			  {
				  unsigned int pipe_number=cell_index_to_pipe_number.find(it->first)->second; //0 to 39 in 2D
				  if (it->second>max_pipe_temperature[pipe_number])
					  max_pipe_temperature[pipe_number]
										   =it->second;
				  if (it->second<min_pipe_temperature[pipe_number])
					  min_pipe_temperature[pipe_number]
										   =it->second;
				  new_avg_pipe_temperature[pipe_number]+=it->second;
				  cell_faces_per_pipe[pipe_number]++;
			  }
		  }
		  current_new_avg_soil_surface_temperature/=cells_on_soil_surface;
		  current_new_avg_road_surface_temperature/=cells_on_road_surface;
		  for (unsigned int i=0; i<number_of_pipes; i++)
			  new_avg_pipe_temperature[i]
									   /=cell_faces_per_pipe[i];
	  }
	  // for (typename std::map<typename DoFHandler<dim>::active_cell_iterator,double >::iterator
	  // 	   it=cell_index_to_current__new_surface_temperature.begin();
	  // 	 it!=cell_index_to_current__new_surface_temperature.end(); ++it)
	  //   {
	  // 	pcout<<it->second<<"\t"
	  // 	     <<cell_index_to_previous_new_surface_temperature.find(it->first)->second<<"\t"
	  // 	     <<cell_index_to_old_surface_temperature.find(it->first)->second<<"\n";
	  //   }
  }

  template<int dim>
  void Heat_Pipe<dim>::update_met_data()
  {
	  if (date_and_time.size()==0 &&
		  met_data.size()     ==0)
	  {
		  if (analytic_met_data)
		  {
			  std::vector< std::vector<int> > initial_date_wrapper;
			  initial_date_wrapper.push_back(initial_date);

			  std::vector< std::vector<int> > initial_date_in_seconds;

			  DataTools data_tools;
			  data_tools.date_to_seconds(initial_date_wrapper,
					  initial_date_in_seconds);
			  std::vector< std::vector<int> > all_dates_in_seconds;
			  for (unsigned int i=0; i<=timestep_number_max; i++)
			  {
				  std::vector<int> all_dates_in_seconds_line;

				  all_dates_in_seconds_line.push_back(initial_date_in_seconds[0][0] +
						  ((int)time_step*i));

				  all_dates_in_seconds.push_back(all_dates_in_seconds_line);
			  }

			  data_tools.seconds_to_date(date_and_time,
					  all_dates_in_seconds);

			  AnalyticSolution analytic_solution(0,0,0,"",false,false,type_of_weather);
			  for (unsigned int i=0; i<date_and_time.size(); i++)
			  {
				  std::vector<double> met_data_line;
				  met_data_line
				  .push_back(analytic_solution.get_analytic_air_temperature(all_dates_in_seconds[i][0]));
				  met_data_line
				  .push_back(analytic_solution.get_analytic_relative_humidity(/*initial_time*/));
				  met_data_line
				  .push_back(analytic_solution.get_analytic_wind_speed(/*initial_time*/));
				  met_data_line
				  .push_back(/*wind direction*/0.);
				  met_data_line
				  .push_back(analytic_solution.get_analytic_solar_radiation(all_dates_in_seconds[i][0]));
				  met_data_line
				  .push_back(analytic_solution.get_analytic_precipitation(/*initial_time*/));
				  /*
				   * there are negative entries in solar radiation and positive
				   * entries in the middle of the night, this should help fix it.
				   */
				  // if (met_data_line[4]<0.)
				  //   met_data_line[4]=0;
				  // if (((date_and_time[i][3]>=21)||
				  //      (date_and_time[i][3]<=2))&&
				  //     (met_data_line[4]>0.))
				  //   met_data_line[4]=0;
				  met_data.push_back(met_data_line);
			  }
			  //output met data
			  std::string output_filename="met_data_ph_";
			  std::ostringstream os;
			  os << preheating_step;
			  output_filename+=os.str() + ".txt";
			  std::ofstream file (output_filename.c_str());
			  if (!file.is_open())
				  throw 2;
			  pcout << "Writing file: " << output_filename.c_str() << std::endl;
			  data_tools.print_data(file,
					  met_data,
					  date_and_time);
			  file.close();
			  if (file.is_open())
				  throw 3;
		  }
		  else
		  {
			  DataTools data_tools;
			  data_tools.read_met_data(date_and_time,
					  met_data,
					  time_step,
					  preheating_step,
					  met_data_type,
					  input_path);
		  }
		  pcout << "\tAvailable met lines: " << met_data.size()
	    		  << std::endl << std::endl;
	  }
	  old_air_temperature   = met_data[timestep_number-1][0];
	  old_relative_humidity = met_data[timestep_number-1][1];
	  old_wind_speed        = met_data[timestep_number-1][2];
	  old_wind_direction    = met_data[timestep_number-1][3];
	  old_solar_radiation   = met_data[timestep_number-1][4];
	  old_precipitation     = met_data[timestep_number-1][5];
	  //
	  new_air_temperature   = met_data[timestep_number][0];
	  new_relative_humidity = met_data[timestep_number][1];
	  new_wind_speed        = met_data[timestep_number][2];
	  new_wind_direction    = met_data[timestep_number][3];
	  new_solar_radiation   = met_data[timestep_number][4];
	  new_precipitation     = met_data[timestep_number][5];
  }
  
  template<int dim>
  void Heat_Pipe<dim>::initial_condition()
  {
	  if (preheating_step>1)
	  {
		  std::ifstream file (("./preheatings/"+preheating_input_filename).c_str());
		  if (!file.is_open())
			  throw 2;

		  Vector<double> initial_condition;
		  initial_condition.block_read (file);

		  file.close();
		  if (file.is_open())
			  throw 3;
	  }
	  else
	  {
		  VectorTools::project(dof_handler,
				  constraints, QGauss<dim>(3),
				  ConstantFunction<dim>(10.),
				  old_solution);
		  old_solution.compress (VectorOperation::insert);
	  }
  }
  
  template<int dim>
  void Heat_Pipe<dim>::run()
  {
    TimerOutput timer (mpi_communicator,
		       pcout,
		       TimerOutput::summary,
		       TimerOutput::cpu_and_wall_times);

    pcout << "\tOutput files (prefix): "
	  << preheating_output_filename << std::endl
	  << std::endl;
    {
      TimerOutput::Scope timer_section(timer,"Read grid");
      read_mesh();
    }
    {
      TimerOutput::Scope timer_section(timer,"Setup system");
      setup_system();
    }
    {
      TimerOutput::Scope timer_section(timer,"Set initial condition");
      initial_condition();
    }
    {
      TimerOutput::Scope timer_section(timer,"Mesh info");
      mesh_info();
      refine_grid();
      mesh_info();
      refine_grid();
      mesh_info();
    }
    /*
      It looks like the system was active whenever the temperature difference between
      the collector and storage was greater than 1.4 C and once was active it stop
      when the difference drop below 0.3 C.
      We define the control switch here so that it keeps its last value, and if it
      was active, and the temperature difference is greater than 0.3 it will remain
      active.
    */
    bool switch_control=false;
    bool previous_switch_control=false;
    //
    double new_control_temperature_collector=0.;
    double new_control_temperature___storage=0.;
    double old_control_temperature_collector=10.;
    //
    double previous_new_collector_avg_norm=0.;
    double previous_new_storage___avg_norm=0.;

    double current__new_collector_avg_norm=0.;
    double current__new_storage___avg_norm=0.;

    std::vector<double> old_inlet__temperatures_pipes(number_of_pipes,0);
    std::vector<double> old_outlet_temperatures_pipes(number_of_pipes,0);
    std::vector<double> previous_new_inlet__temperatures_pipes(number_of_pipes,0);
    //    std::vector<double> previous_new_outlet_temperatures_pipes(number_of_pipes,0);
    std::vector<double> current__new_inlet__temperatures_pipes(number_of_pipes,0);
    std::vector<double> current__new_outlet_temperatures_pipes(number_of_pipes,0);
    //
    /*
     * The actual loop in time. The maximum time for the simulation, time step,
     * initial time and many other variables are defined in the constructor
     */
    for (timestep_number=1, time=time_step;
	 timestep_number<=timestep_number_max;
	 timestep_number++, time+=time_step)
      {
	/*
	 * Update meteorological data
	 */
	{
	  TimerOutput::Scope timer_section (timer,"Update met data");
	  update_met_data ();
	}
	/*
	 * Prepare vectors with data at borehole's
	 * sensor depths. We do this every time step.
	 */
	//		  {
	//			  TimerOutput::Scope timer_section (timer,"Fill output vectors");
	//			  fill_output_vectors();
	//		  }
	/*
	 * In the experimental data provided by TRL, in the sensor located nearest to the
	 * surface, it can be observed a change in the daily variations of temperature for
	 * the months of December to March. It is believe that this effect is produced by
	 * different canopy densities above the soil's surface.
	 */
	canopy_density=parameters.canopy_density;
	if (author=="Best")
	  if (date_and_time[timestep_number][1]>=10 &&
	      date_and_time[timestep_number][1]<=2)
	    canopy_density=parameters.canopy_density;
	/*
	 * Here we define and initialise variables for convergence
	 * criteria. First, those corresponding to the surface
	 * temperature convergence. We also need a variable to
	 * tell us how many times have the loop been performed
	 * in each time step.
	 */
	current__new_collector_avg_norm=0.;
	current__new_storage___avg_norm=0.;

	double tolerance_collector_avg_norm=-1000.;
	double tolerance_storage___avg_norm=-1000.;
	double tolerance_soil_avg_surface_temperature=-1000.;
	double tolerance_road_avg_surface_temperature=-1000.;
	double tolerance_limit_soil=0.005;
	double tolerance_limit_road=0.005;
	// if (date_and_time[timestep_number][1]==6)
	//   tolerance_limit_soil=0.8;
	/*
	 * Then those corresponding to the pipe system convergence. We too
	 * compare the heat flux at the collector and storage pipes in the
	 * following way: average the collector heat flux for all pipes and
	 * compare the new and old values. When the difference between these
	 * values is less than 10 Watts, break the loop.
	 * We also need vectors that define the current state of the pipe
	 * system. We will work with these temporal vectors and we will
	 * update the originals once the solution converges. These vectors
	 * are meant to store just the current state of the system, not the
	 * state through the whole simulation.
	 * Here we also need a variable to tell us how many times has this
	 * loop been performed.
	 */
	/*
	 * We want to store the soil and road heat and mass fluxes at each
	 * time step. This is done in a vectors of vectors, a kind of matrix.
	 * Every line corresponds to a time step. As we don't know a priori
	 * how many time steps are going to be performed, we add a new line
	 * every time we enter a new time step. The line is rewritten
	 * every time the system is assembled and when the system converges
	 * it will store the final heat fluxes for that time step.
	 */
	for (unsigned int i=0; i<number_of_pipes; i++)
	  current__new_pipe_heat_flux[i]=0.;

	unsigned int step=0;
	do
	  {
	    /*
	     * surface temperature convergence
	     */
	    for (unsigned int i=0; i<road_heat_fluxes[timestep_number-1].size(); i++)
	      road_heat_fluxes[timestep_number-1][i]=0.;
	    for (unsigned int i=0; i<soil_heat_fluxes[timestep_number-1].size(); i++)
	      soil_heat_fluxes[timestep_number-1][i]=0.;
	    {
	      TimerOutput::Scope timer_section (timer,"Assemble temperature");
	      assemble_system_parallel(switch_control,step);
	      assemble_system_petsc();
	    }
	    {
	      TimerOutput::Scope timer_section (timer,"Solve temperature");
	      solve();
	    }
	    double avg_collector__inlets=0.;
	    double avg_collector_outlets=0.;
	    double avg_storage____inlets=0.;
	    double avg_storage___outlets=0.;
	    {
	      TimerOutput::Scope timer_section (timer,"Update surface temperatures");
	      previous_new_avg_soil_surface_temperature
		=current_new_avg_soil_surface_temperature;
	      previous_new_avg_road_surface_temperature
		=current_new_avg_road_surface_temperature;

	      previous_new_collector_avg_norm
		=current__new_collector_avg_norm;
	      previous_new_storage___avg_norm
		=current__new_storage___avg_norm;

	      surface_temperatures();

	      current__new_collector_avg_norm=0.;
	      current__new_storage___avg_norm=0.;

	      for (unsigned int i=0; i<number_of_pipes/2; i++)
		{
		  current__new_collector_avg_norm
		    +=new_avg_pipe_temperature[i]/(number_of_pipes/2);

		  current__new_storage___avg_norm
		    +=new_avg_pipe_temperature[(number_of_pipes/2)+i]/(number_of_pipes/2);

		  if (i<number_of_pipes/4)
		    {
		      avg_collector__inlets
			+=max_pipe_temperature[i]/(number_of_pipes/4);
		      avg_storage____inlets
			+=max_pipe_temperature[(number_of_pipes/2)+i]/(number_of_pipes/4);
		      avg_collector_outlets
			+=max_pipe_temperature[(number_of_pipes/4)+i]/(number_of_pipes/4);
		      avg_storage___outlets
			+=max_pipe_temperature[(number_of_pipes/4)+(number_of_pipes/2)+i]/(number_of_pipes/4);
		    }
		}
	      /*define tolerances*/
	      tolerance_soil_avg_surface_temperature
		=fabs(current_new_avg_soil_surface_temperature
		      -previous_new_avg_soil_surface_temperature);
	      tolerance_road_avg_surface_temperature
		=fabs(current_new_avg_road_surface_temperature
		      -previous_new_avg_road_surface_temperature);

	      tolerance_collector_avg_norm
		=fabs(current__new_collector_avg_norm
		      -previous_new_collector_avg_norm);
	      tolerance_storage___avg_norm
		=fabs(current__new_storage___avg_norm
		      -previous_new_storage___avg_norm);
	    }
	    //==========================================================================================
	    /*-----solve pipe system ------*/
	    if (step==0)
	      {
		if (preheating_step==4 ||
		    preheating_step==7)
		  {
		    new_control_temperature_collector
		      =current__new_collector_avg_norm;
		    new_control_temperature___storage
		      =current__new_storage___avg_norm;
		  }
		else if (preheating_step==5 ||
			 preheating_step==8)
		  {
		    const Vector<double> localized_solution_temperature(old_solution);

		    new_control_temperature_collector
		      =VectorTools::point_value(dof_handler,
						localized_solution_temperature,
						Point<dim>(0.,-0.025));
		    new_control_temperature___storage
		      =current__new_storage___avg_norm;
		  }
		control_temperatures[timestep_number-1][0]=
		  new_control_temperature_collector;
		control_temperatures[timestep_number-1][1]=
		  new_control_temperature___storage;
		/*
		 * Here is implemented the activation of the system. There are two main ways:
		 *
		 * --1-- The system is activated automatically if a certain criteria is meet.
		 * At the moment this criteria is the temperature difference between the
		 * average temperature at the surface of collector and storage pipes. Two
		 * main periods of time are identified in the experimental results:
		 * from 23/08/2005 to 14/11/2005 and from 15/11/2005 to 20/02/2006
		 * --2-- The system is forced to be active in certain ranges of time (i.e.
		 * between noon and 10pm everyday).
		 */
		if (activation_type=="automatic_activation")
		  {
		    // first period: from 23/08/2005 to 14/11/2005
		    if (preheating_step==4 ||
			preheating_step==7)
		      {
			if (((new_control_temperature_collector-new_control_temperature___storage)>1.4) || //1.4
			    (switch_control &&
			     ((new_control_temperature_collector-new_control_temperature___storage)>0.4))) //0.4
			  switch_control=true;
			else
			  switch_control=false;
			/*
			 * If there is any interval where the system is off or on for any
			 * external reason (e.g. failure) modify the followig IF statement.
			 */
			if ((preheating_step==4)&&
			    (date_and_time[timestep_number][0]==23 &&
			     date_and_time[timestep_number][1]==8  &&
			     date_and_time[timestep_number][2]==2005 &&
			     (date_and_time[timestep_number][3]<13 ||
			      (date_and_time[timestep_number][3]==13 &&
			       date_and_time[timestep_number][4]<0))))
			  switch_control=false;
			else if ((preheating_step==7)&&
				 ((date_and_time[timestep_number][1]==5  &&
				   date_and_time[timestep_number][2]==2006 &&
				   date_and_time[timestep_number][0]>=18)||
				  (date_and_time[timestep_number][1]==6  &&
				   date_and_time[timestep_number][2]==2006 &&
				   date_and_time[timestep_number][0]<5)))
			  switch_control=false;
		      }
		    else if (preheating_step==5 ||// second period: from 15/11/2005 to 20/02/2006
			     preheating_step==8)
		      {
			double control_temperature=4.;
			if ((old_control_temperature_collector<control_temperature)&&
			    (new_control_temperature_collector<control_temperature))
			  switch_control=true;
			else if (switch_control &&
				 (old_control_temperature_collector>control_temperature)&&
				 (new_control_temperature_collector>control_temperature))
			  switch_control=false;
			else
			  switch_control=false;

			if (new_control_temperature___storage<
			    new_control_temperature_collector)
			  switch_control=false;
		      }
		    else
		      switch_control=false;
		  }
		else if (activation_type=="forced_activation")
		  {
		    if ((date_and_time[timestep_number][3]>=14) &&
			(date_and_time[timestep_number][3]<=20) &&
			(date_and_time[timestep_number][1]<10))
		      switch_control=true;
		    else
		      switch_control=false;
		  }
		else
		  {
		    pcout << "Error. Wrong activation type\n";
		    throw -1;
		  }
	      }

	    if ((pipe_system==true)&&
		(switch_control==true))
	      {
		if ((previous_switch_control==false)&&
		    (switch_control==true)&&
		    (step==0))
		  {
		    for (unsigned int i=0; i<number_of_pipes/2; i++)
		      {
			current__new_inlet__temperatures_pipes[   i]=
			  new_avg_pipe_temperature[20+i];
			current__new_inlet__temperatures_pipes[20+i]=
			  new_avg_pipe_temperature[   i];

			old_pipe_heat_flux[   i]=0.;
			old_pipe_heat_flux[20+i]=0.;
		      }
		  }
		else
		  current__new_inlet__temperatures_pipes
		    =previous_new_inlet__temperatures_pipes;

		std::vector<double> current_heat_flux_temp(number_of_pipes,0);
		PipeSystem system_pipes(time_step);

		system_pipes.pipe_heat_flux(new_avg_pipe_temperature,
					    old_avg_pipe_temperature,
					    current__new_inlet__temperatures_pipes,
					    current__new_outlet_temperatures_pipes,
					    current_heat_flux_temp);
		for (unsigned int i=0; i<number_of_pipes; i++)
		  current__new_pipe_heat_flux[i]+=
		    current_heat_flux_temp[i];

		previous_new_inlet__temperatures_pipes
		  =current__new_inlet__temperatures_pipes;
	      }
	    step++;
	    
	    if (step>100 && step<120)
	      {
		pcout << "\t" << tolerance_soil_avg_surface_temperature << " -- "
		      << tolerance_limit_soil << "\n"
		      << "\t" << tolerance_road_avg_surface_temperature << " -- "
		      << tolerance_limit_road << "\n";
	      }
	    
	    cell_index_to_previous_new_surface_temperature
	      =cell_index_to_current__new_surface_temperature;
	  }while ((tolerance_soil_avg_surface_temperature>tolerance_limit_soil) ||
		  (tolerance_road_avg_surface_temperature>tolerance_limit_road) ||
		  ((tolerance_collector_avg_norm>0.1)&&(pipe_system==true)&&(switch_control==true))||
		  ((tolerance_storage___avg_norm>0.1)&&(pipe_system==true)&&(switch_control==true)));

	pcout << "Time step " << timestep_number << "\t"
	      << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][0] << "/"
	      << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][1] << "/"
	      << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][2] << "\t"
	      << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][3] << ":"
	      << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][4] << ":"
	      << std::setw(2) << std::setfill('0') << date_and_time[timestep_number][5];
	std::cout.setf( std::ios::fixed, std::ios::floatfield );
	pcout << "\tTa:" << std::setw(5) << std::setfill(' ') << std::setprecision(2) << new_air_temperature
	      << "\tRs:" << std::setw(7) << std::setfill(' ') << std::setprecision(2) << new_solar_radiation
	      << "\tUs:" << std::setw(5) << std::setfill(' ') << std::setprecision(2) << new_wind_speed
	      << "\tHr:" << std::setw(6) << std::setfill(' ') << std::setprecision(2) << new_relative_humidity
	      << "\tI :" << std::setw(5) << std::setfill(' ') << std::setprecision(2) << new_precipitation
	      << "\tc :" << std::setw(4) << std::setfill(' ') << std::setprecision(2) << canopy_density
	      << "\ts :" << std::setw(3) << std::setfill(' ') << std::setprecision(2) << step
	      << std::endl;
	{
	  /*
	   * Output the solution at the beggining, end and every
	   * certain time stepsy:
	   */
	  if (parameters.output_vtu_files)
	    {
	      TimerOutput::Scope timer_section (timer,"Output results");
	      output_results();
	    }
	  /*
	   * At the end of the simulation we output the previous
	   * defined vectors and visualization files
	   */
	  if (timestep_number==timestep_number_max)
	    {
	      TimerOutput::Scope timer_section (timer,"Output text files");
	      const Vector<double> localized_solution_temperature (solution);
	      if (this_mpi_process==0)
		{
		  std::vector< std::vector<int> >::const_iterator
		    first=date_and_time.begin(), second=date_and_time.begin()+timestep_number_max;
		  std::vector< std::vector<int> > date_and_time_1d(first,second);
		  /*
		   * Print file with data at borehole
		   * sensor's depths generate suffix
		   */
		  {
		    std::stringstream p;
		    p << output_path << "/" << preheating_output_filename;
		    std::string prefix = p.str();

		    std::vector< std::string > filenames;
		    //						  filenames.push_back(prefix+"_bha_temperature.txt");
		    //						  filenames.push_back(prefix+"_bhf_temperature.txt");
		    //						  filenames.push_back(prefix+"_bhh_temperature.txt");
		    //						  filenames.push_back(prefix+"_bhi_temperature.txt");
		    filenames.push_back(prefix+"_road_heat_fluxes.txt");
		    filenames.push_back(prefix+"_soil_heat_fluxes.txt");

		    if (pipe_system==true)
		      {
			filenames.push_back(prefix+"_pipe_heat_fluxes.txt");
			filenames.push_back(prefix+"_control_temperatures.txt");
		      }
		    std::vector< std::vector< std::vector<double> > > data;
		    //						  data.push_back(soil_bha_temperature);
		    //						  data.push_back(soil_bhf_temperature);
		    //						  data.push_back(soil_bhh_temperature);
		    //						  data.push_back(soil_bhi_temperature);
		    data.push_back(road_heat_fluxes);
		    data.push_back(soil_heat_fluxes);
		    if (pipe_system==true)
		      {
			data.push_back(pipe_heat_fluxes);
			data.push_back(control_temperatures);
		      }

		    for (unsigned int f=0; f<filenames.size(); f++)
		      {
			std::ofstream file (filenames[f].c_str());
			if (!file.is_open())
			  throw 2;
			pcout << "Writing file: " << filenames[f].c_str() << std::endl;
			DataTools data_tools;
			data_tools.print_data(file,
					      data[f],
					      date_and_time_1d);
			file.close();
			if (file.is_open())
			  throw 3;
		      }
		  }
		  /*
		   * Print preheating files
		   */
		  {
		    std::ofstream file_temperature (output_path+"/"+preheating_output_filename.c_str());
		    if (!file_temperature.is_open())
		      throw 2;
		    localized_solution_temperature.block_write(file_temperature);
		    file_temperature.close();
		    if (file_temperature.is_open())
		      throw 3;
		  }
		}
	    }
	}
	/*
	 * update old solution to the current solution
	 * update everything that need to be updated
	 */
	control_temperatures.resize(control_temperatures.size()+1,std::vector<double>(2));
	road_heat_fluxes.resize(road_heat_fluxes.size()+1,std::vector<double>(number_of_surface_heat_and_mass_fluxes));
	soil_heat_fluxes.resize(soil_heat_fluxes.size()+1,std::vector<double>(number_of_surface_heat_and_mass_fluxes));
	{
	  old_solution=solution;

	  cell_index_to_old_surface_temperature
	    =cell_index_to_current__new_surface_temperature;
	  old_avg_soil_surface_temperature
	    =current_new_avg_soil_surface_temperature;
	  old_avg_road_surface_temperature
	    =current_new_avg_road_surface_temperature;

	  old_avg_pipe_temperature
	    =new_avg_pipe_temperature;
	  old_inlet__temperatures_pipes
	    =current__new_inlet__temperatures_pipes;
	  old_outlet_temperatures_pipes
	    =current__new_outlet_temperatures_pipes;

	  old_pipe_heat_flux
	    =current__new_pipe_heat_flux;

	  previous_switch_control=switch_control;
	  old_control_temperature_collector
	    =new_control_temperature_collector;

	  cell_index_to_old_outbound_coefficient
	    =cell_index_to_new_outbound_coefficient;

	  cell_index_to_old_inbound_flux
	    =cell_index_to_new_inbound_flux;

	  cell_index_to_old_boundary_coefficient_and_fluxes_road
	    =cell_index_to_new_boundary_coefficient_and_fluxes_road;;
	  cell_index_to_old_boundary_coefficient_and_fluxes_soil
	    =cell_index_to_new_boundary_coefficient_and_fluxes_soil;
	}
      }
    /*
     * Nothing better than a job well done (hopefully)
     */
    pcout << std::endl
	  << std::endl << "\t"
	  << "\t Job Done!!"
	  << std::endl;
  }
}

int main(int argc, char **argv)
{
  const unsigned int dim=2;
	
  try
    {
      using namespace dealii;
      using namespace TRL;

      Utilities::MPI::MPI_InitFinalize mpi_initialization(argc,argv,1);
      {
	deallog.depth_console (0);

	Heat_Pipe<dim> trl_problem(argc,argv);
	trl_problem.run ();
      }
    }
  catch (std::exception &exc)
    {
      std::cerr << std::endl << std::endl
		<< "----------------------------------------------------"
		<< std::endl;
      std::cerr << "Exception on processing: " << std::endl
		<< exc.what() << std::endl
		<< "Aborting!" << std::endl
		<< "----------------------------------------------------"
		<< std::endl;

      return 1;
    }
  catch (...)
    {
      std::cerr << std::endl << std::endl
		<< "----------------------------------------------------"
		<< std::endl;
      std::cerr << "Unknown exception!" << std::endl
		<< "Aborting!" << std::endl
		<< "----------------------------------------------------"
		<< std::endl;
      return 1;
    }

  return 0;
}
