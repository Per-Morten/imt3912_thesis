class ComponentInfo:
    type = 0
    access = UNKNOWN
    set = []

initialize_data(component_info_list, # 1
                execution_layers,
                collections): # 2

    for collection in collections:
        metaInfo = collection.get_meta_information()

        if should_be_executed(metaInfo):
            new_component = metaInfo.get_component_info()

            # 3
            if new_component.access == READ_WRITE or UNKNOWN:
                execution_order.append(new_component.type)
            else:
                # 4
                for type in new_component.set:
                    if type == new_component_info.type:
                        new_component.set.erase(type)
    
                if new_component.access == INDEPENDENT:
                    new_component.set.clear()
    
                component_info_list.append(new_component_info)

    # 5
    for info in component_info_list:
        for type in info.set:

            component_info = component_info_list.find_info(type)
            component_info.set.append(type)             

# 1: A list containing instances of the ComponentInfo type
# 2: A list of collections, where each collection contains all the data for each component type
# 3: Places read write and unknown into their own seperate layers
# 4: Remove all self reads for the components read list
# 5: Ensures if A read B, that B also reads A
