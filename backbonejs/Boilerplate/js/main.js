// Ovveride Underscore.js' template format                                      
_.templateSettings = {                                                          
    evaluate: /\{%([\s\S]+?)%\}/g,                                              
    interpolate: /\{\{(.+?)\}\}/g                                               
};

// Models
var Vehicle = Backbone.Model.extend({
    urlRoot: '/api/vehicles',
    validate: function(attrs) {
        if (!attrs.registrationNumber)
            return "Registration number required!";
    },
    start: function() {
        console.log('Vehicle started.');
    }
});

var Vehicles = Backbone.Collection.extend({
    model: Vehicle 
});

var vehicles = new Vehicles([
    new Vehicle({ registrationNumber: "XLI887", colour: "Blue" }),
    new Vehicle({ registrationNumber: "ZNP123", colour: "Blue" }),
    new Vehicle({ registrationNumber: "XUV456", colour: "Gray" })  
]);

var VehicleView = Backbone.View.extend({
    tagName: 'li',
    
    initialize: function(options) {
        ;
    },
    
    render: function() {
        this.$el.html('Registration: ' + this.model.get('registrationNumber'));
        
        return this;
    }
});

var VehiclesView = Backbone.View.extend({
    tagName: 'ul',
    
    initialize: function(options) {
        this.bus = options.bus;
        
        this.bus.on("updated", this.render, this);
    },
    
    render: function() {
        this.$el.html('');
        var self = this;
        this.model.each(function(vehicle) {
           var vehicleView = new VehicleView({ model: vehicle });
           self.$el.append(vehicleView.render().$el); 
        });
        
        return this;
    }
});

var NewVehicleView = Backbone.View.extend({
    el: '#vehicleForm',
    
    events: {
        "click button": "onSubmit"
    },
    
    initialize: function(options) {
        this.bus = options.bus
    },
    
    onSubmit: function() {
        $registrationField = this.$el.find('#registrationNumber');
        var registrationNumber = $registrationField.val();
        // Add the vehicle
        vehicles.add(new Vehicle({ registrationNumber: registrationNumber }));
        // Trigger the change bus.
        this.bus.trigger('updated');
        $registrationField.val('');
    },
    
    render: function() {
        return this;
    }
});

var bus = _.extend({}, Backbone.Events);

var newVehicleView = new NewVehicleView({ bus: bus });
newVehicleView.render();

var vehiclesView = new VehiclesView({ el: '#container', model: vehicles, bus: bus });
vehiclesView.render();





var Car = Vehicle.extend({
    start: function() {
        console.log('Car with registration number ' + this.get('registrationNumber') + ' started.');
    }
});

// Collections
var Song = Backbone.Model.extend({
    defaults: {
        listeners: 0
    }
});

var Songs = Backbone.Collection.extend({
    model: Song
});

var songs = new Songs([
    new Song({ title: "The Bee's Knees", genre: "Jazz" }),
    new Song({ title: "All of Me", genre: "Pop" }) 
]);

songs.add(new Song({ title: "Songs 3", genre: "Jazz" }));

var JazzList = songs.where({ genre: "Jazz" });

// Views
var SongView = Backbone.View.extend({
    initialize: function() {
        this.model.on("change", this.render, this);
    },
    
    render: function() {
        var template = _.template($('#songTemplate').html());
        var html = template(this.model.toJSON());
        this.$el.html(html);
        
        // this.$el.html(this.model.get("title") + " - Listeners: " + this.model.get("listeners"));
        
        return this;
    }
});

var SongsView = Backbone.View.extend({    
    render: function() {
        this.$el.html('');
        var self = this;
        this.model.each(function(song){
            var songView = new SongView({ model: song });
            self.$el.append(songView.render().$el);
        });
    }
});

var song = new Song({ title: "Blue in Green", plays: 1100 });
/*var songView = new SongView({ el: "#container", model: song });
songView.render();*/

// var songsView = new SongsView({ el: "#songs", model: songs });
// songsView.render();

// EVENTS
var person = {
    name: "Mosh",
    
    walk: function() {
        this.trigger("walking", {
            speed: 1,
            startTime: "08:00"
        });
    }
};

_.extend(person, Backbone.Events);

/*person.on("walking", function(e) {
    console.log("Person is walking.");
    console.log("Event Args", e);
});

// person.off("walking");
person.walk();*/
