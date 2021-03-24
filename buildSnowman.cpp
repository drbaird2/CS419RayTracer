
void Scene::build(void){
    int num_samples = 1;

    //viewplane

    vp.set_hres(500);
    vp.set_vres(500);
    vp.set_pixel_size(1);
    vp.set_samples(num_samples);

    Ambient* ambient_ptr = new Ambient;
    ambient_ptr->scale_radiance(1.0);
    set_ambient_light(ambient_ptr);
    background_color = solidblue;
    tracer_ptr = new RayCast(this);

    //camera

    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(0,0,100);
    pinhole_ptr->set_look(0,0,0);
    pinhole_ptr->set_view_distance(500);
    pinhole_ptr->uvwbase();
    set_camera(pinhole_ptr);

    //light

    Ambient* light_ptr1 = new Ambient;
    add_light(light_ptr1);

    //Material

    double ka = 0.25;
    double kd = 0.75;

    //Materials

    Matte* matte_green = new Matte;
    matte_green->set_ka(ka);
    matte_green->set_kd(kd);
    matte_green->set_cd(solidgreen);

    Matte* matte_blue = new Matte;
    matte_blue->set_ka(ka);
    matte_blue->set_kd(kd);
    matte_blue->set_cd(solidblue);

    Matte* matte_red = new Matte;
    matte_red->set_ka(ka);
    matte_red->set_kd(kd);
    matte_red->set_cd(solidred);

    Matte* matte_crimson = new Matte;
    matte_crimson->set_ka(ka);
    matte_crimson->set_kd(kd);
    matte_crimson->set_cd(crimson);

    //Shapes
    Plane* land = new Plane(vec3(0,-250,-1), point3(0,-100,-1), Color(0.0 ,1.0 ,0.0));
    Sphere* head = new Sphere(point3(0,.75,-1), 0.35, Color(0.0 ,0.0 ,1.0));
    Sphere* middle = new Sphere(point3(0,0,-1), .5, Color(1.0 ,0.0 ,0.0));
    Sphere* butt = new Sphere(point3(0,-.6,-1), 0.65, Color(0.0 ,1.0 ,0.0));
    Triangle* nose1 = new Triangle(point3(0,.75,-.5),point3(.2,.75,-1), point3(0,.9,-1), Color(0.5, 0.25, 0.25));
    Triangle* nose2 = new Triangle(point3(0,.75,-.5),point3(-.2,.75,-1), point3(0,.9,-1), Color(0.5, 0.25, 0.25));
    
    land->set_material(matte_green);
    head->set_material(matte_blue);
    middle->set_material(matte_red);
    butt->set_material(matte_blue);
    nose1->set_material(matte_crimson);
    nose2->set_material(matte_crimson);

    add_object(land);
    add_object(head);
    add_object(middle);
    add_object(butt);
    add_object(nose1);
    add_object(nose2);


}